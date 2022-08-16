# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coder <coder@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/14 15:08:37 by rda-silv          #+#    #+#              #
#    Updated: 2022/08/16 00:28:08 by coder            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= so_long

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -g

MINILIBX = -lmlx -lXext -lX11

LIBFT = ./library/libft/libft.a

SRCDIR = source
OBJDIR = object

COMPILE = so_long.c hooks.c walk.c collectible.c check_map.c \
getting_map.c getting_position.c validate.c walk_aux.c check_error.c

SRC = $(addprefix $(SRCDIR)/, $(COMPILE))
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

TAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):	$(OBJDIR) $(OBJ)
		make -C library/libft
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MINILIBX) $(LIBFT)

$(OBJDIR)/%.o:	$(SRCDIR)/%.c
				$(CC) $(CFLAGS) -c $< -o $@	-I./source -I./library/libft

$(OBJDIR):
		mkdir -p $(OBJDIR)

clean:
		make clean -C library/libft
		rm -rf $(OBJDIR)

fclean: clean
		rm -f $(NAME)
		make fclean -C library/libft

re: fclean all