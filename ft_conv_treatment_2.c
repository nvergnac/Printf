/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_treatment_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 14:17:05 by nvergnac          #+#    #+#             */
/*   Updated: 2018/01/03 19:33:48 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_big_wchar_conv(t_lst *first, intmax_t val)
{
	char		*str;

	if ((val >= 55296 && val <= 57343) || val >= 1114112)
	{
		first->ret = -1;
		str = NULL;
	}
	else if (val < 65536)
	{
		first->read_bytes = first->read_bytes + 3;
		str = ft_strnew(3);
		str[0] = val / 4096 + 128 + 64 + 32;
		str[1] = (val - (val / 4096) * 4096) / 64 + 128;
		str[2] = val % 64 + 128;
	}
	else
	{
		first->read_bytes = first->read_bytes + 4;
		str = ft_strnew(4);
		str[0] = val / 262144 + 128 + 64 + 32 + 16;
		str[1] = (val - (val / 262144) * 262144) / 4096 + 128;
		str[2] = (val - (val / 4096) * 4096) / 64 + 128;
		str[3] = val % 64 + 128;
	}
	return (str);
}

char	*ft_wchar_setlocale_check(t_lst *first)
{
	char		*str;
	intmax_t	val;

	val = first->value_signed;
	if (val >= 256)
	{
		first->ret = -2;
		str = ft_strdup("");
	}
	else
	{
		first->read_bytes = first->read_bytes + 1;
		str = ft_strnew(1);
		str[0] = (char)val;
	}
	return (str);
}

char	*ft_wchar_conv(t_lst *first)
{
	char		*str;
	intmax_t	val;

	if (MB_CUR_MAX == 1)
		return (ft_wchar_setlocale_check(first));
	val = first->value_signed;
	if (val < 128)
	{
		first->read_bytes = first->read_bytes + 1;
		str = ft_strnew(1);
		str[0] = val;
	}
	else if (val < 2048)
	{
		first->read_bytes = first->read_bytes + 2;
		str = ft_strnew(2);
		str[0] = val / 64 + 128 + 64;
		str[1] = val % 64 + 128;
	}
	else
		str = ft_big_wchar_conv(first, val);
	return (str);
}

char	*ft_char_conv(t_lst *first)
{
	char	*str;

	if (first->mdf)
	{
		if (ft_strcmp(first->mdf, "l") == 0)
			return (ft_wchar_conv(first));
	}
	str = ft_strnew(1);
	str[0] = (unsigned char)(first->value_signed);
	first->read_bytes = 1;
	return (str);
}

char	*ft_signed_conv_treatment(t_lst *first)
{
	uintmax_t	value;

	if (ft_strcmp(first->v_type, "int") == 0)
		value = (uintmax_t)((unsigned int)first->value_signed);
	else
		value = (uintmax_t)first->value_signed;
	if (first->type == 'd')
		return (ft_itoa_base_intmax(first->value_signed, "0123456789"));
	if (first->type == 'o')
		return (ft_itoa_base_uintmax(value, "01234567"));
	if (first->type == 'u')
		return (ft_itoa_base_uintmax(value, "0123456789"));
	if (first->type == 'x')
		return (ft_itoa_base_uintmax(value, "0123456789abcdef"));
	if (first->type == 'X')
		return (ft_itoa_base_uintmax(value, "0123456789ABCDEF"));
	if (first->type == 'c')
		return (ft_char_conv(first));
	return (NULL);
}
