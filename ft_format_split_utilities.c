/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_split_utilities.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 18:24:10 by pclement          #+#    #+#             */
/*   Updated: 2018/01/02 19:27:39 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv(char *format, int st, int flag, t_info *inf_ptr)
{
	if (flag == 0 && format[st] != '%')
		return (0);
	if (flag == 0 && format[st] == '%')
		st++;
	if (ft_type(format, st, inf_ptr) >= 1 && flag <= 5)
		return (1);
	if (ft_mdf(format, st, inf_ptr) >= 1 && flag <= 4)
		return (ft_conv(format, st + ft_mdf(format, st, inf_ptr), 5, inf_ptr));
	if (ft_acc(format, st, inf_ptr) >= 1 && flag <= 3)
		return (ft_conv(format, st + ft_acc(format, st, inf_ptr), 4, inf_ptr));
	if (ft_size(format, st, inf_ptr) >= 1 && flag <= 2)
		return (ft_conv(format, st + ft_size(format, st, inf_ptr), 3, inf_ptr));
	if (ft_flag(format, st, inf_ptr) >= 1 && flag <= 1)
		return (ft_conv(format, st + ft_flag(format, st, inf_ptr), 2, inf_ptr));
	return (0);
}

int		ft_add_spec_lst(t_lst *first, t_info *info_struct_ptr)
{
	t_lst	*new_lst;
	t_lst	*index;
	int		len;

	len = 0;
	index = first;
	while (index->next)
		index = index->next;
	new_lst = ft_lst_init();
	new_lst->flags = ft_strdup(info_struct_ptr->flags);
	len = len + ft_strlen(new_lst->flags);
	new_lst->size = ft_strdup(info_struct_ptr->size);
	len = len + ft_strlen(new_lst->size);
	new_lst->acc = ft_strdup(info_struct_ptr->acc);
	len = len + ft_strlen(new_lst->acc);
	new_lst->mdf = ft_strdup(info_struct_ptr->mdf);
	len = len + ft_strlen(new_lst->mdf);
	new_lst->type = info_struct_ptr->type;
	ft_reinit_struct(info_struct_ptr);
	len++;
	index->next = new_lst;
	return (len);
}

void	ft_add_str_lst(char *format, int i, int start, t_lst *first)
{
	t_lst	*new_lst;
	t_lst	*index;
	char	*str;
	int		k;

	str = ft_strnew(i - start + 1);
	k = 0;
	while (k < i - start)
	{
		str[k] = format[start + k];
		k++;
	}
	index = first;
	while (index->next)
		index = index->next;
	new_lst = ft_lst_init();
	new_lst->init_str = ft_strdup(str);
	index->next = new_lst;
	str = ft_safe_free(str);
}
