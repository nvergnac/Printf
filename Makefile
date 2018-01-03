# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile_libftprintf.a                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pclement <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/20 16:13:50 by pclement          #+#    #+#              #
#    Updated: 2018/01/03 17:12:26 by pclement         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror -c
SRC = libft/ft_strcat.c libft/ft_strchr.c libft/ft_strcpy.c libft/ft_strncpy.c libft/ft_strdup.c libft/ft_strlen.c\
	  libft/ft_strncat.c libft/ft_strlcat.c libft/ft_strrchr.c libft/ft_strstr.c libft/ft_strnstr.c \
	  libft/ft_strcmp.c libft/ft_strncmp.c libft/ft_atoi.c libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_isalnum.c\
	  libft/ft_isascii.c libft/ft_isprint.c libft/ft_toupper.c libft/ft_tolower.c libft/ft_memset.c\
	  libft/ft_bzero.c libft/ft_memcpy.c libft/ft_memccpy.c libft/ft_memmove.c libft/ft_memchr.c libft/ft_memcmp.c\
	  libft/ft_memalloc.c libft/ft_memdel.c libft/ft_strnew.c libft/ft_strdel.c libft/ft_strclr.c\
	  libft/ft_striter.c libft/ft_striteri.c libft/ft_strmap.c libft/ft_strmapi.c libft/ft_strequ.c\
	  libft/ft_strnequ.c libft/ft_strsub.c libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_strsplit.c\
	  libft/ft_itoa.c libft/ft_putchar.c libft/ft_putstr.c libft/ft_putendl.c libft/ft_putnbr.c\
	  libft/ft_putnbr_intmax.c\
	  libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_lstnew.c\
	  libft/ft_lstadd.c libft/ft_lstdelone.c libft/ft_lstdel.c libft/ft_lstiter.c\
	  libft/ft_count_if.c libft/ft_wstrlen.c libft/ft_wstrnew.c\
	  ft_accuracy_treatment.c ft_str_pos_ins.c ft_conv_if.c\
	  ft_conv_if_utilities.c ft_format_split_utilities.c\
	  ft_safe_free.c\
	  ft_format_split.c ft_lst_utilities.c\
	  ft_printf.c ft_varg_1.c ft_varg_2.c ft_printf_itoa_base.c\
	  ft_conv_treatment_1.c ft_conv_treatment_2.c ft_conv_treatment_3.c\
	  ft_get_clean_flag_0.c ft_get_clean_flag_1.c ft_get_clean_flag_2.c ft_get_clean_flag_3.c ft_display.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC) $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(%.o):
	gcc $(FLAGS) %.c

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
