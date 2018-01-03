/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_clean_flag_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 19:40:39 by nvergnac          #+#    #+#             */
/*   Updated: 2018/01/02 19:42:44 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_fill_flag(char a, char *flag)
{
	int			i;

	i = 0;
	while (flag[i] != 0)
		i++;
	if (a == ' ' && flag[i - 1] == '+' && i >= 1)
		return (flag);
	if (a == '-' && flag[i - 1] == '0' && i >= 1)
	{
		flag[i - 1] = '-';
		return (flag);
	}
	flag[i] = a;
	return (flag);
}

void			ft_clean_flag(t_lst *first)
{
	const char	*ref;
	char		*flag;
	int			i;

	flag = ft_strnew(6);
	ref = "#+ 0-'";
	while (*ref != 0)
	{
		i = 0;
		while (first->flags[i])
		{
			if (first->flags[i] == *ref)
			{
				flag = ft_fill_flag(*ref, flag);
				break ;
			}
			i++;
		}
		ref++;
	}
	first->flags = ft_safe_free(first->flags);
	first->flags = ft_strdup(flag);
	flag = ft_safe_free(flag);
}

void			ft_put_size(t_lst *first)
{
	char		*added_str;

	if (first->type != 'c' && ft_atoi(first->size) >
			(int)ft_strlen(first->init_str))
	{
		added_str = ft_create_fill_str(first, ' ');
		first->init_str = ft_str_pos_ins(first->init_str, 0, added_str);
		added_str = ft_safe_free(added_str);
	}
}

void			ft_get_clean_flag(t_lst *first)
{
	while (first)
	{
		if (first->flags || first->type == 'c' || first->type == '%')
		{
			if (first->flags)
				ft_clean_flag(first);
			if (first->type == 's' || first->type == 'u' || first->type == '%')
				ft_clean_flag_su(first);
			if (first->type == 'c')
				ft_clean_flag_c(first);
			if (first->type == 'd')
				ft_clean_flag_d(first);
			if (first->type == 'o')
				ft_clean_flag_o(first);
			if (first->type == 'x' || first->type == 'X')
				ft_clean_flag_x(first);
		}
		ft_put_size(first);
		first = first->next;
	}
}
