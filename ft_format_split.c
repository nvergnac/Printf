/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 13:09:28 by pclement          #+#    #+#             */
/*   Updated: 2018/01/02 19:27:59 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_else_spec_flag(int spec_flag, int *start_ptr, int i)
{
	if (spec_flag == 1)
		*start_ptr = i;
	return (0);
}

void	ft_init_format_split(t_split *sp_sct)
{
	sp_sct->i = 0;
	sp_sct->spec_flag = 1;
	sp_sct->start = 0;
	sp_sct->first = ft_lst_init();
	sp_sct->info_struct = ft_info_init();
}

t_lst	*ft_format_split(char *format)
{
	t_split	sp_sct;

	ft_init_format_split(&sp_sct);
	while (format[sp_sct.i] != 0)
	{
		if (ft_conv(format, sp_sct.i, 0, &(sp_sct.info_struct)) >= 1)
		{
			if (sp_sct.spec_flag == 0)
				ft_add_str_lst(format, sp_sct.i, sp_sct.start, sp_sct.first);
			sp_sct.spec_flag = 1;
			sp_sct.spec_size = ft_add_spec_lst(sp_sct.first,
					&(sp_sct.info_struct));
			sp_sct.i = sp_sct.i + sp_sct.spec_size;
		}
		else
		{
			sp_sct.spec_flag = ft_else_spec_flag(sp_sct.spec_flag,
					&(sp_sct.start), sp_sct.i);
		}
		(sp_sct.i)++;
	}
	if (sp_sct.spec_flag == 0)
		ft_add_str_lst(format, sp_sct.i, sp_sct.start, sp_sct.first);
	ft_empty_struct(&(sp_sct.info_struct));
	return (sp_sct.first);
}
