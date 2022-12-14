# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/16 07:52:44 by rda-silv          #+#    #+#              #
#    Updated: 2022/08/20 12:54:08 by rda-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##### SET VARIABLES #####
# NAME
NAME=so_long

#COMPILE
CC=gcc

#FLAGS TO COMPILE
CC_FLAGS= -g -Wall -Wextra -Werror
MLX_FLAGS=-lmlx -lXext -lX11

#VALGRIND
VALGRIND=valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
         -q --tool=memcheck

#DIRECTORIES
SRC_DIR=source
OBJ_DIR=object
LIB_DIR=library

#LIBRARIES
LIBFT=./$(LIB_DIR)/libft/libft.a

#SOURCE CODES
# SRCS=so_long.c input_validator.c open_map_file.c tracker.c
SRCS=so_long.c input_validator.c open_map_file.c tracker.c reset_variables.c \
     free_all.c handle_checks.c exception_manager.c handle_window.c \
	 handle_game.c handle_gameplay.c handle_walk.c walk_aux.c \
	 handle_collect.c

#GET ALL SOURCES FILES
SRC=$(addprefix $(SRC_DIR)/,$(SRCS))

#CONVERT .C IN .O
OBJ=$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

##### COMPILATION AND LINKING #####
#START HERE!
all: $(NAME)

#LINKING .O FILES AND TRANSFORM IN BINARY (so_long), AND EXECUTE LIBFT :)
$(NAME): $(OBJ_DIR) $(OBJ)
	make -C $(LIB_DIR)/libft
	$(CC) $(CC_FLAGS) $(OBJ) -o $(NAME) $(MLX_FLAGS) $(LIBFT)

#CREATE .O FILES BY .C FILES (ONE BY ONE) - %:TAKES CORE NAME
#$@ TARGET NAME AND $< FIRST PRE_REQUISIT
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CC_FLAGS) -c $< -o $@

#CREATE OBJ_DIR (IF EXISTS, DO NOTHING)
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

#CLEANING (REMOVING .O DIRECTORY AND INSIDE LIBFT THE .O FILES)
clean:
	make clean -C $(LIB_DIR)/libft
	rm -rf $(OBJ_DIR)

#MAKE CLEANING AND DELETE BINARY FILE
fclean: clean
	make fclean -C $(LIB_DIR)/libft
	rm -f $(NAME)

#SHORTCUT TO CLEAN ALL
re: fclean all

#VALGRIND
vg: re
	$(VALGRIND) ./$(NAME)

#SHORTCUT TO CLEAN ALL
.PHONY: all clean