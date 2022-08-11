# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/27 19:12:48 by rda-silv          #+#    #+#              #
#    Updated: 2022/04/13 08:54:33 by rda-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT	:= libft
NAME	:= libftprintf.a
CFLAGS	:= -Wall -Wextra -Werror -c
CC		:= gcc
SRCS	:=	ft_printf.c \
			ft_filter_flags.c \
			ft_putchar_plus \
			ft_print_character \
			ft_print_string \
			ft_print_pointer \
			ft_print_decimal \
			ft_print_positive_int \
			ft_uitoa \
			ft_print_hex

OBJ		:= $(SRCS:%.c=%.o)

all		: $(NAME)

$(NAME)	: $(OBJ)
	make  -C $(LIBFT)
	cp libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJ)

%.o		: %.c
	$(CC) $(CFLAGS) $<

clean	:
	rm -f $(OBJ)
	make clean -C $(LIBFT)

fclean	: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re		: fclean all
	
.PHONY	: all clear re fclean