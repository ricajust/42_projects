# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/14 15:08:37 by rda-silv          #+#    #+#              #
#    Updated: 2022/08/17 21:59:37 by rda-silv         ###   ########.fr        #
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
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
		mkdir -p $(OBJDIR)

clean:
		make clean -C library/libft
		rm -rf $(OBJDIR)

fclean: clean
		rm -f $(NAME)
		make fclean -C library/libft

re: fclean all