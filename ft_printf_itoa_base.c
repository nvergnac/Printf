/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:30:41 by pclement          #+#    #+#             */
/*   Updated: 2018/01/04 14:58:05 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_neg(intmax_t value, int base_size)
{
	if (value < 0)
	{
		if (base_size == 10)
			return (2);
	}
	return (1);
}

/*
**Doesn't take into account sign if base different from 10
*/

uintmax_t	ft_abs(intmax_t value)
{
	uintmax_t	result;

	if (value < 0)
		return ((uintmax_t)(-value));
	return ((uintmax_t)value);
}

char		*ft_itoa_base_intmax(intmax_t value, char *base)
{
	char		*tab;
	int			tab_len;
	uintmax_t	result;
	int			neg;
	int			i;

	neg = ft_neg(value, ft_strlen(base));
	result = ft_abs(value);
	tab_len = neg;
	while ((result = result / ft_strlen(base)) >= 1)
		tab_len++;
	if (!(tab = ft_strnew(tab_len + 1)))
		return (0);
	result = ft_abs(value);
	i = 0;
	while (++i <= tab_len)
	{
		tab[tab_len - i] = base[result % ft_strlen(base)];
		result = result / ft_strlen(base);
	}
	if (neg == 2)
		tab[0] = '-';
	return (tab);
}

/*
**Only for uintmax_t everything positive. cast before
*/

char		*ft_itoa_base_uintmax(uintmax_t value, char *base)
{
	char		*tab;
	int			tab_len;
	uintmax_t	result;
	int			i;

	result = value;
	tab_len = 1;
	while ((value = value / ft_strlen(base)) >= 1)
		tab_len++;
	if (!(tab = ft_strnew(tab_len + 1)))
		return (0);
	i = 0;
	while (++i <= tab_len)
	{
		tab[tab_len - i] = base[result % ft_strlen(base)];
		result = result / ft_strlen(base);
	}
	return (tab);
}
