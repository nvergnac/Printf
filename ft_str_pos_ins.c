/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_pos_ins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:39:31 by pclement          #+#    #+#             */
/*   Updated: 2018/01/03 15:36:13 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_parameters_check(char *str, char *ins_str)
{
	char	*result;

	if (str == 0 || ins_str == 0 ||
		!(result = ft_strnew(ft_strlen(str) + ft_strlen(ins_str))))
		return (NULL);
	return (result);
}

char	*ft_str_pos_ins(char *str, int pos, char *ins_str)
{
	char	*result;
	int		index;
	int		i;

	if (!(result = ft_parameters_check(str, ins_str)))
		return (NULL);
	index = 0;
	while (index < pos && str[index] != 0)
	{
		result[index] = str[index];
		index++;
	}
	i = 0;
	while (i < (int)ft_strlen(ins_str))
	{
		result[index + i] = ins_str[i];
		i++;
	}
	while (str[index] != 0)
	{
		result[index + i] = str[index];
		index++;
	}
	str = ft_safe_free(str);
	return (result);
}
