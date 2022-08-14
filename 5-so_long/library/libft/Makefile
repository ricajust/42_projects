# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/14 17:13:34 by rda-silv          #+#    #+#              #
#    Updated: 2022/08/14 17:40:03 by rda-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = $(wildcard *.c)

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
