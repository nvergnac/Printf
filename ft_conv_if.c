/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:13:14 by nvergnac          #+#    #+#             */
/*   Updated: 2018/01/03 14:06:52 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_type(char *format, int st, t_info *inf)
{
	int		j;
	char	*type_str;

	type_str = "sSpdDioOuUxXcC%";
	j = 0;
	while (type_str[j] != 0)
	{
		if (format[st] == type_str[j])
		{
			inf->type = type_str[j];
			return (1);
		}
		j++;
	}
	return (0);
}

int		ft_mdf(char *format, int st, t_info *inf)
{
	int		j;
	char	*mdf_str;

	mdf_str = "hljz";
	j = 0;
	while (mdf_str[j] != 0)
	{
		if (format[st] == mdf_str[j] && mdf_str[j] != 'h' && mdf_str[j] != 'l')
		{
			inf->mdf = ft_safe_free(inf->mdf);
			inf->mdf = ft_strnew(1);
			inf->mdf[0] = mdf_str[j];
			return (1);
		}
		if (ft_chk_spec_mdf(format, st, mdf_str[j], inf) > 0)
			return (ft_chk_spec_mdf(format, st, mdf_str[j], inf));
		j++;
	}
	return (0);
}

int		ft_acc(char *format, int st, t_info *inf)
{
	int		k;
	char	*tmp;

	if (format[st] != '.')
		return (0);
	if (!(tmp = ft_strnew(1)))
		exit(0);
	tmp[0] = '.';
	k = 1;
	while (format[st + k] >= '0' && format[st + k] <= '9')
	{
		if (!(tmp = ft_append_acc_char(format[st + k], k, tmp)))
			exit(0);
		k++;
	}
	inf->acc = ft_safe_free(inf->acc);
	if (!(inf->acc = ft_strdup(tmp)))
		exit(0);
	tmp = ft_safe_free(tmp);
	return (k);
}

int		ft_size(char *format, int st, t_info *inf)
{
	int		k;
	char	*tmp;

	k = 0;
	if (format[st] >= '1' && format[st] <= '9')
	{
		if (!(tmp = ft_strnew(1)))
			exit(0);
		while (format[st + k] >= '0' && format[st + k] <= '9')
		{
			if (!(tmp = ft_append_size_char(format[st + k], k, tmp)))
				exit(0);
			k++;
		}
		inf->size = ft_safe_free(inf->size);
		if (!(inf->size = ft_strdup(tmp)))
			exit(0);
		tmp = ft_safe_free(tmp);
		return (k);
	}
	return (0);
}

int		ft_flag(char *format, int st, t_info *inf)
{
	t_flag		flag;

	ft_init_flag(&flag);
	while (format[st + flag.k] != 0 && flag.switch_flag == 0)
	{
		flag.j = 0;
		while (flag.flag_str[flag.j] != 0)
		{
			flag.switch_flag = 1;
			if (flag.flag_str[flag.j++] == format[st + flag.k])
			{
				if (!(flag.tmp = ft_apd_flg_chr(format[st + flag.k], flag)))
					exit(0);
				flag.switch_flag = 0;
				break ;
			}
		}
		flag.k++;
	}
	inf->flags = ft_safe_free(inf->flags);
	inf->flags = ft_strdup(flag.tmp);
	flag.tmp = ft_safe_free(flag.tmp);
	return (flag.k - 1);
}
