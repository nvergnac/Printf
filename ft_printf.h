/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 13:09:23 by pclement          #+#    #+#             */
/*   Updated: 2018/01/04 14:56:08 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include "libft/libft.h"
# define FRB first->read_bytes

typedef struct		s_flag
{
	char			*tmp;
	char			*flag_str;
	int				j;
	int				k;
	int				switch_flag;
}					t_flag;

typedef struct		s_info
{
	char			*flags;
	char			*size;
	char			*acc;
	char			*mdf;
	char			type;
}					t_info;

typedef struct		s_lst
{
	char			*init_str;
	char			*flags;
	char			*size;
	char			*acc;
	char			*mdf;
	char			type;
	char			*v_type;
	void			*value_ptr;
	intmax_t		value_signed;
	uintmax_t		value_unsigned;
	int				read_bytes;
	int				ret;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_split
{
	t_lst			*first;
	t_info			info_struct;
	int				i;
	int				spec_size;
	int				start;
	int				spec_flag;
}					t_split;

struct				s_va_type
{
	char			*v_type;
	void			(*ft_va_ptr)(va_list vl);
};
/*
**ft_format_split et fonctions dependantes : transforme format en une listes
**exploitable
*/
int					ft_printf(const char *format, ...);
t_lst				*ft_format_split(char *format);
t_lst				ft_struct_init();
t_lst				*ft_struct_fill(char *str);
t_lst				*ft_lst_pushback();
void				ft_empty_struct(t_info *info_struct_ptr);
void				ft_empty_lst(t_lst *first);
t_lst				*ft_lst_init(void);
t_info				ft_info_init(void);
void				ft_reinit_struct(t_info *info_struct_ptr);
int					ft_add_spec_lst(t_lst *first, t_info *info_struct_ptr);
void				ft_add_str_lst(char *format, int i, int start,
		t_lst *first);
int					ft_conv(char *format, int st, int flag, t_info *inf_ptr);
t_lst				*ft_delete_first(t_lst *first);
/*
**Fonctions utiles pour ft_conv
*/
int					ft_type(char *format, int st, t_info *inf);
int					ft_mdf(char *format, int st, t_info *inf);
int					ft_chk_spec_mdf(char *format, int st, char mdf_str,
		t_info *info);
int					ft_acc(char *format, int st, t_info *inf);
char				*ft_append_acc_char(char format, int k, char *tmp);
int					ft_size(char *format, int st, t_info *inf);
char				*ft_append_size_char(char format, int k, char *tmp);
int					ft_flag(char *format, int st, t_info *inf);
char				*ft_apd_flg_chr(char format, t_flag flag);
void				ft_init_flag(t_flag *flag_ptr);
/*
**Fonctions utiles pour afficher les listes
*/
void				ft_lst_show(t_lst *first);
void				ft_print_lst(t_lst *first, int n);
void				ft_info_show(t_info info_struct);
int					ft_display(t_lst *first);
char				*ft_safe_free(char *str);
/*
**Fonctions utiles pour va_arg
*/
char				*ft_v_type(char type, char *mdf);
void				ft_v_type_clean(t_lst *first);
void				*va_arg_void(va_list ap, char *v_type);
intmax_t			va_arg_intmax(va_list ap, char *v_type);
uintmax_t			va_arg_uintmax(va_list ap, char *v_type);
char				*ft_itoa_base(intmax_t n, int base);
/*
**Fonctions de conversions
*/
char				*ft_itoa_base_intmax(intmax_t value, char *base);
char				*ft_itoa_base_uintmax(uintmax_t value, char *base);
void				ft_conv_treatment(t_lst *first);
char				*ft_wchar_conv(t_lst *first);
char				*ft_val_filled(char *v_type);
char				*ft_signed_conv_treatment(t_lst *first);
char				*ft_val_filled(char *v_type);
char				*ft_fct(t_lst *first, char *added_str, char *str, int pos);
/*
**Fonctions utiles pour traitement options
*/
char				*ft_str_pos_ins(char *str, int pos, char *ins_str);
void				ft_accuracy_treatment(t_lst *first);
/*
**Fonctions get_clean_flag
*/
int					ft_add_char(t_lst *first, char c);
void				ft_fill_char(t_lst *first, char c, int neg);
void				ft_left_justif(t_lst *first);
char				*ft_fill_flag(char a, char *flag);
void				ft_clean_flag(t_lst *first);
void				ft_clean_flag_su(t_lst *first);
void				ft_clean_flag_c(t_lst *first);
void				ft_clean_flag_d(t_lst *first);
void				ft_clean_flag_o(t_lst *first);
void				ft_clean_flag_x(t_lst *first);
void				ft_clean_flag_p(t_lst *first);
void				ft_get_clean_flag(t_lst *first);
char				*ft_create_fill_str(t_lst *first, char c);

#endif
