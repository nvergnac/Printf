/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 16:43:08 by pclement          #+#    #+#             */
/*   Updated: 2018/01/03 14:06:56 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_chk_spec_mdf(char *format, int st, char mdf_str, t_info *info)
{
	if (format[st] == mdf_str && (mdf_str == 'h' || mdf_str == 'l'))
	{
		if (format[st + 1] == mdf_str)
		{
			info->mdf = ft_safe_free(info->mdf);
			info->mdf = ft_strnew(2);
			info->mdf[0] = mdf_str;
			info->mdf[1] = mdf_str;
			return (2);
		}
		else
		{
			info->mdf = ft_safe_free(info->mdf);
			info->mdf = ft_strnew(1);
			info->mdf[0] = mdf_str;
			return (1);
		}
	}
	return (0);
}

char	*ft_append_acc_char(char format, int k, char *tmp)
{
	char	*buf;

	buf = ft_strdup(tmp);
	tmp = ft_safe_free(tmp);
	if (!(tmp = ft_strnew(ft_strlen(buf) + 1)))
		exit(0);
	ft_strcpy(tmp, buf);
	buf = ft_safe_free(buf);
	tmp[k] = format;
	return (tmp);
}

char	*ft_append_size_char(char format, int k, char *tmp)
{
	char	*buf;

	buf = ft_strdup(tmp);
	tmp = ft_safe_free(tmp);
	if (!(tmp = ft_strnew(ft_strlen(buf) + 1)))
		exit(0);
	ft_strcpy(tmp, buf);
	buf = ft_safe_free(buf);
	tmp[k] = format;
	return (tmp);
}

char	*ft_apd_flg_chr(char format, t_flag flag)
{
	char	*buf;

	if (flag.k == 0)
	{
		if (!(flag.tmp = ft_strnew(1)))
			exit(0);
	}
	buf = ft_strdup(flag.tmp);
	flag.tmp = ft_safe_free(flag.tmp);
	if (!(flag.tmp = ft_strnew(ft_strlen(buf) + 1)))
		exit(0);
	ft_strcpy(flag.tmp, buf);
	buf = ft_safe_free(buf);
	flag.tmp[flag.k] = format;
	return (flag.tmp);
}

void	ft_init_flag(t_flag *flag_ptr)
{
	flag_ptr->flag_str = "#0-+ ";
	flag_ptr->k = 0;
	flag_ptr->tmp = 0;
	flag_ptr->switch_flag = 0;
}
