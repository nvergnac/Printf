/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_clean_flag_rework.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 18:20:27 by nvergnac          #+#    #+#             */
/*   Updated: 2018/01/02 19:50:15 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_add_char(t_lst *first, char c)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!(tmp = ft_strnew((int)ft_strlen(first->init_str) + 1)))
		exit(0);
	tmp[0] = c;
	if (first->init_str)
	{
		while (first->init_str[i] != 0)
		{
			tmp[i + 1] = first->init_str[i];
			i++;
		}
		free(first->init_str);
	}
	if (!(first->init_str = ft_strdup(tmp)))
		exit(0);
	tmp = ft_safe_free(tmp);
	return (1);
}

void		ft_fill_char(t_lst *first, char c, int neg)
{
	char	*tmp;
	char	*str;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!(tmp = ft_strnew(ft_atoi(first->size))))
		exit(0);
	if (!(str = ft_strdup(first->init_str)))
		exit(0);
	while (i < (ft_atoi(first->size) - (int)ft_strlen(str) - neg))
		tmp[i++] = c;
	while (i < ft_atoi(first->size))
		tmp[i++] = str[k++];
	first->init_str = ft_safe_free(first->init_str);
	if (!(first->init_str = ft_strdup(tmp)))
		exit(0);
	tmp = ft_safe_free(tmp);
	str = ft_safe_free(str);
}

char		*ft_create_fill_str(t_lst *first, char c)
{
	int		size_to_fill;
	char	*fill_str;
	int		i;

	i = 0;
	if (first->type != 'c')
		size_to_fill = ft_atoi(first->size) - (int)ft_strlen(first->init_str);
	else
		size_to_fill = ft_atoi(first->size) - FRB;
	if (!(fill_str = ft_strnew(size_to_fill)))
		exit(0);
	while (i < size_to_fill)
	{
		fill_str[i] = c;
		i++;
	}
	return (fill_str);
}

void		fill_init_str(t_lst *first, char *str, int i)
{
	while (i < ft_atoi(first->size))
	{
		first->init_str[i] = str[i];
		i++;
	}
}

void		ft_left_justif(t_lst *first)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = ft_strnew(ft_atoi(first->size))))
		exit(0);
	if (first->init_str)
	{
		while (first->init_str[i])
		{
			str[i] = first->init_str[i];
			i++;
		}
		first->init_str = ft_safe_free(first->init_str);
	}
	if (FRB)
		i = FRB;
	while (i < ft_atoi(first->size))
		str[i++] = ' ';
	if (!(first->init_str = ft_strnew(ft_atoi(first->size))))
		exit(0);
	i = 0;
	fill_init_str(first, str, i);
	str = ft_safe_free(str);
}
