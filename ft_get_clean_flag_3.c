/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_clean_flag_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 19:48:25 by nvergnac          #+#    #+#             */
/*   Updated: 2018/01/02 19:49:42 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_clean_flag_c(t_lst *first)
{
	int		i;
	char	*added_str;

	i = 0;
	if (first->flags)
	{
		while (first->flags[i])
		{
			if (first->flags[i] == '0' && (ft_atoi(first->size) > FRB))
			{
				added_str = ft_create_fill_str(first, '0');
				first->init_str = ft_str_pos_ins(first->init_str, 0, added_str);
				added_str = ft_safe_free(added_str);
			}
			if (first->flags[i] == '-' && (ft_atoi(first->size) > FRB))
				ft_left_justif(first);
			i++;
		}
	}
	if (ft_atoi(first->size) > FRB && !first->flags)
	{
		added_str = ft_create_fill_str(first, ' ');
		first->init_str = ft_str_pos_ins(first->init_str, 0, added_str);
		added_str = ft_safe_free(added_str);
	}
}

void		ft_check_0_su(t_lst *first, int i)
{
	char	*added_str;

	if (first->flags[i] == '0' && !(first->acc && first->type == 'u') &&
			(ft_atoi(first->size) > (int)ft_strlen(first->init_str)))
	{
		added_str = ft_create_fill_str(first, '0');
		first->init_str = ft_str_pos_ins(first->init_str, 0, added_str);
		added_str = ft_safe_free(added_str);
	}
}

void		ft_clean_flag_su(t_lst *first)
{
	int		i;

	i = 0;
	if (first->type == '%')
	{
		if (!(first->init_str = ft_strnew(1)))
			exit(0);
		first->init_str[0] = '%';
	}
	if (first->flags)
	{
		while (first->flags[i])
		{
			ft_check_0_su(first, i);
			if (first->flags[i] == '-' && (ft_atoi(first->size) >
						(int)ft_strlen(first->init_str)))
				ft_left_justif(first);
			i++;
		}
	}
}

void		ft_check_0_d(t_lst *first, int i, int neg)
{
	char	*added_str;

	if (first->flags[i] == '0' && !first->acc &&
			(ft_atoi(first->size) > ((int)ft_strlen(first->init_str))))
	{
		added_str = ft_create_fill_str(first, '0');
		first->init_str = ft_str_pos_ins(first->init_str, neg, added_str);
		added_str = ft_safe_free(added_str);
	}
}

void		ft_clean_flag_d(t_lst *first)
{
	int		i;
	int		neg;
	char	*added_str;

	neg = 0;
	i = 0;
	if (first->init_str && first->init_str[0] == '-')
		neg = 1;
	while (first->flags[i])
	{
		if (first->flags[i] == ' ' && neg == 0)
			neg = neg + ft_add_char(first, ' ');
		if (first->flags[i] == '+' && neg == 0)
			neg = neg + ft_add_char(first, '+');
		ft_check_0_d(first, i, neg);
		if (first->flags[i] == '-' && (ft_atoi(first->size) >
					(int)ft_strlen(first->init_str)))
			ft_left_justif(first);
		i++;
	}
}
