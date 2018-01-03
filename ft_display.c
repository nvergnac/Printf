/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 14:49:15 by pclement          #+#    #+#             */
/*   Updated: 2018/01/03 19:27:40 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_lst	*ft_delete_first(t_lst *first)
{
	t_lst	*tmp;

	if (first)
	{
		tmp = first;
		if (first->next)
			first = first->next;
		free(tmp);
	}
	return (first);
}

void	ft_read_bytes(t_lst *first)
{
	int		size_nb;

	size_nb = 0;
	if (first->size)
		size_nb = ft_atoi(first->size);
	if (first->read_bytes == 0)
		first->read_bytes = (int)ft_strlen(first->init_str);
	else
	{
		if (size_nb > first->read_bytes)
			first->read_bytes = size_nb;
	}
}

int		ft_check_ret(t_lst *first)
{
	while (first)
	{
		if (first->ret == -1)
			return (-1);
		first = first->next;
	}
	return (0);
}

int		ft_check_ret2(t_lst *first, int *int_ptr)
{
	if (first->ret == -2)
	{
		first->ret = -1;
		*int_ptr = -1;
		return (1);
	}
	if (first->type == 0)
	{
		if (first->next)
		{
			if (first->next->ret == -2)
			{
				first->ret = -1;
				*int_ptr = -1;
				return (1);
			}
		}
	}
	return (0);
}

int		ft_display(t_lst *first)
{
	int		total_read_bytes;

	total_read_bytes = 0;
	if (ft_check_ret(first) == -1)
		total_read_bytes = -1;
	while (first && total_read_bytes >= 0)
	{
		if (ft_check_ret2(first, &total_read_bytes) == 1)
			break ;
		ft_read_bytes(first);
		total_read_bytes = total_read_bytes + first->read_bytes;
		write(1, first->init_str, first->read_bytes);
		first = first->next;
	}
	while (first && total_read_bytes == -1 && first->ret != -1)
	{
		ft_read_bytes(first);
		if (first->type != 0)
			write(1, first->init_str, first->read_bytes);
		first = first->next;
	}
	return (total_read_bytes);
}
