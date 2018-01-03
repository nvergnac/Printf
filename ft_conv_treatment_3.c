/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_treatment_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 14:17:05 by nvergnac          #+#    #+#             */
/*   Updated: 2018/01/03 19:27:03 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_val_filled(char *v_type)
{
	char	*str;

	str = 0;
	if ((ft_strcmp(v_type, "int") == 0) || (ft_strcmp(v_type, "short int") == 0)
			|| (ft_strcmp(v_type, "signed char") == 0)
			|| (ft_strcmp(v_type, "long") == 0)
			|| (ft_strcmp(v_type, "long long") == 0)
			|| (ft_strcmp(v_type, "intmax_t") == 0)
			|| (ft_strcmp(v_type, "ssize_t") == 0)
			|| (ft_strcmp(v_type, "wint_t") == 0))
		str = ft_strdup("value_signed");
	if ((ft_strcmp(v_type, "size_t") == 0)
			|| (ft_strcmp(v_type, "unsigned short int") == 0)
			|| (ft_strcmp(v_type, "unsigned char") == 0)
			|| (ft_strcmp(v_type, "unsigned long") == 0)
			|| (ft_strcmp(v_type, "unsigned long long") == 0)
			|| (ft_strcmp(v_type, "uintmax_t") == 0))
		str = ft_strdup("value_unsigned");
	if ((ft_strcmp(v_type, "char *") == 0)
			|| (ft_strcmp(v_type, "wchar_t *") == 0)
			|| (ft_strcmp(v_type, "void *") == 0))
		str = ft_strdup("value_ptr");
	return (str);
}

char	*ft_fct(t_lst *first, char *added_str, char *str, int pos)
{
	if (first->read_bytes == ft_atoi(first->acc + 1))
		str = ft_str_pos_ins(str, pos, added_str);
	else
		first->read_bytes = first->read_bytes - (int)ft_strlen(added_str);
	added_str = ft_safe_free(added_str);
	return (str);
}
