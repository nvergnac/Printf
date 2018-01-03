/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_treatment_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 14:22:00 by nvergnac          #+#    #+#             */
/*   Updated: 2018/01/03 19:27:06 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_unsigned_conv_treatment(t_lst *first)
{
	char	*str;

	str = NULL;
	if (first->type == 'o')
		str = ft_itoa_base_uintmax(first->value_unsigned, "01234567");
	if (first->type == 'u')
		str = ft_itoa_base_uintmax(first->value_unsigned, "0123456789");
	if (first->type == 'x')
		str = ft_itoa_base_uintmax(first->value_unsigned, "0123456789abcdef");
	if (first->type == 'X')
		str = ft_itoa_base_uintmax(first->value_unsigned, "0123456789ABCDEF");
	return (str);
}

char	*ft_wstr_conv_treatment(t_lst *first, int acc_nb)
{
	char	*added_str;
	int		i;
	char	*str;
	int		pos;

	i = 0;
	pos = 0;
	str = ft_strnew(0);
	while (((wchar_t *)first->value_ptr)[i] != 0)
	{
		first->value_signed = ((wchar_t *)first->value_ptr)[i];
		added_str = ft_wchar_conv(first);
		if ((acc_nb > 0 && first->read_bytes >= acc_nb))
		{
			str = ft_fct(first, added_str, str, pos);
			break ;
		}
		str = ft_str_pos_ins(str, pos, added_str);
		added_str = ft_safe_free(added_str);
		pos = first->read_bytes;
		i++;
	}
	return (str);
}

char	*ft_wstr_conv(t_lst *first)
{
	char	*str;
	int		acc_nb;

	acc_nb = 0;
	if (first->acc)
		acc_nb = ft_atoi(first->acc + 1);
	if (!first->value_ptr)
		return (ft_strdup("(null)"));
	str = ft_wstr_conv_treatment(first, acc_nb);
	return (str);
}

char	*ft_str_conv_treatment(t_lst *first)
{
	char	*str;

	if (first->mdf)
	{
		if (ft_strcmp(first->mdf, "l") == 0)
			return (ft_wstr_conv(first));
	}
	if (!(str = ft_strdup((char *)first->value_ptr)))
		str = ft_strdup("(null)");
	return (str);
}

void	ft_conv_treatment(t_lst *first)
{
	char	*str;

	while (first)
	{
		if (first->v_type)
		{
			if ((str = ft_val_filled(first->v_type)))
			{
				if (ft_strcmp(str, "value_signed") == 0)
					first->init_str = ft_signed_conv_treatment(first);
				if (ft_strcmp(str, "value_unsigned") == 0)
					first->init_str = ft_unsigned_conv_treatment(first);
				if (ft_strcmp(str, "value_ptr") == 0)
					first->init_str = ft_str_conv_treatment(first);
			}
			str = ft_safe_free(str);
		}
		first = first->next;
	}
}
