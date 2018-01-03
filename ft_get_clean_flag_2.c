/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_clean_flag_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 19:42:52 by nvergnac          #+#    #+#             */
/*   Updated: 2018/01/02 19:52:39 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_put_0(t_lst *first)
{
	if (first->init_str)
	{
		if ((((ft_atoi(first->init_str) != 0 && !first->acc) ||
						(first->acc && ft_atoi(first->acc + 1) == 0) ||
						(first->acc && (ft_atoi(first->acc + 1) <=
										(int)ft_strlen(first->init_str) &&
										(first->init_str[0] != '0' ||
										first->init_str[0] == 0))))))
		{
			ft_add_char(first, '0');
			return (1);
		}
	}
	return (0);
}

void		ft_clean_flag_o(t_lst *first)
{
	int		i;
	int		neg;
	char	*added_str;

	neg = 0;
	i = 0;
	while (first->flags[i])
	{
		if (first->flags[i] == '#')
			neg = ft_put_0(first);
		if (first->flags[i] == '0' && !first->acc && (ft_atoi(first->size) >
					(int)ft_strlen(first->init_str)))
		{
			added_str = ft_create_fill_str(first, '0');
			first->init_str = ft_str_pos_ins(first->init_str, neg, added_str);
			added_str = ft_safe_free(added_str);
		}
		if (first->flags[i] == '-' && (ft_atoi(first->size) >
					(int)ft_strlen(first->init_str)))
			ft_left_justif(first);
		i++;
	}
}

int			ft_put_0x(t_lst *first, int neg, int i)
{
	if (first->flags[i] == '#' && !(first->value_unsigned == 0 &&
				first->value_signed == 0))
	{
		if (first->type == 'X')
			neg = neg + ft_add_char(first, 'X');
		else
			neg = neg + ft_add_char(first, 'x');
		neg = neg + ft_add_char(first, '0');
	}
	if (first->ret == 1 && first->value_unsigned == 0)
	{
		first->init_str = ft_safe_free(first->init_str);
		first->init_str = ft_strdup("0x0");
		neg = 3;
	}
	return (neg);
}

void		ft_clean_flag_x(t_lst *first)
{
	int		i;
	int		neg;
	char	*added_str;

	neg = 0;
	i = 0;
	if (first->init_str)
	{
		while (first->flags[i])
		{
			neg = ft_put_0x(first, neg, i);
			if (first->flags[i] == '0' && !first->acc && (ft_atoi(first->size) >
						(int)ft_strlen(first->init_str)))
			{
				added_str = ft_create_fill_str(first, '0');
				first->init_str = ft_str_pos_ins(first->init_str, neg,
						added_str);
				added_str = ft_safe_free(added_str);
			}
			if (first->flags[i] == '-' && (ft_atoi(first->size) >
						(int)ft_strlen(first->init_str)))
				ft_left_justif(first);
			i++;
		}
	}
}
