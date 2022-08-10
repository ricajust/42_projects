# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 0021/07/29 22:47:16 by da-silv           #+#    #+#              #
#    Updated: 2021/09/02 18:33:04 by rda-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS		=	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
				ft_isprint.c ft_toupper.c ft_tolower.c ft_strlen.c\
				ft_strlcat.c ft_strlcpy.c ft_strchr.c ft_strrchr.c \
				ft_strncmp.c ft_strnstr.c ft_memset.c ft_memcpy.c ft_memchr.c\
				ft_memcmp.c ft_memmove.c ft_bzero.c ft_atoi.c ft_calloc.c\
				ft_strdup.c ft_putchar_fd.c ft_putstr_fd.c ft_substr.c\
				ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c\
				ft_striteri.c ft_putendl_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
				ft_memccpy.c\

OBJ	=	$(SRCS:.c=.o)

CC	=	gcc

CFLAGS	=	-Wall -Werror -Wextra

NAME	=	libft.a

rm	=	rm -f

LIB	=	ar rc

all:	$(NAME)

.c.o: 
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJ)
	$(LIB) $(NAME) $(OBJ)

clean: 
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean	all

runw:
	bash ./libft-war-machine/grademe.sh
	
.PHONY: all clear re fclean
