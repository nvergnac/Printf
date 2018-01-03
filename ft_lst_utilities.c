/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 18:07:04 by pclement          #+#    #+#             */
/*   Updated: 2018/01/03 14:01:50 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_info	ft_info_init(void)
{
	t_info	new_info;

	new_info.flags = NULL;
	new_info.size = NULL;
	new_info.acc = NULL;
	new_info.mdf = NULL;
	new_info.type = 0;
	return (new_info);
}

t_lst	*ft_lst_init(void)
{
	t_lst	*new_lst;

	if (!(new_lst = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	new_lst->init_str = NULL;
	new_lst->flags = NULL;
	new_lst->size = NULL;
	new_lst->acc = 0;
	new_lst->mdf = NULL;
	new_lst->type = 0;
	new_lst->next = NULL;
	new_lst->v_type = NULL;
	new_lst->value_ptr = 0;
	new_lst->value_signed = 0;
	new_lst->value_unsigned = 0;
	new_lst->read_bytes = 0;
	new_lst->ret = 0;
	return (new_lst);
}

void	ft_empty_lst(t_lst *first)
{
	t_lst	*index;

	while (first)
	{
		first->init_str = ft_safe_free(first->init_str);
		first->flags = ft_safe_free(first->flags);
		first->size = ft_safe_free(first->size);
		first->acc = ft_safe_free(first->acc);
		first->mdf = ft_safe_free(first->mdf);
		first->v_type = 0;
		first->value_ptr = 0;
		index = first->next;
		free(first);
		first = index;
	}
}

void	ft_empty_struct(t_info *info_struct_ptr)
{
	if (info_struct_ptr)
	{
		info_struct_ptr->flags = ft_safe_free(info_struct_ptr->flags);
		info_struct_ptr->size = ft_safe_free(info_struct_ptr->size);
		info_struct_ptr->acc = ft_safe_free(info_struct_ptr->acc);
		info_struct_ptr->mdf = ft_safe_free(info_struct_ptr->mdf);
		info_struct_ptr->type = 0;
	}
}

void	ft_reinit_struct(t_info *info_struct_ptr)
{
	if (info_struct_ptr)
	{
		info_struct_ptr->flags = ft_safe_free(info_struct_ptr->flags);
		info_struct_ptr->size = ft_safe_free(info_struct_ptr->size);
		info_struct_ptr->acc = ft_safe_free(info_struct_ptr->acc);
		info_struct_ptr->mdf = ft_safe_free(info_struct_ptr->mdf);
		info_struct_ptr->type = 0;
	}
}
