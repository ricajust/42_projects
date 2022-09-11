# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/06 07:57:57 by rda-silv          #+#    #+#              #
#    Updated: 2022/09/11 15:05:29 by rda-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##### SET VARIABLES #####
# NAME
NAME=pipex

#COMPILE
CC=gcc

#FLAGS TO COMPILE
CC_FLAGS= -g -Wall -Wextra -Werror

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
SRCS=pipex.c validators.c pipering.c finding.c executing.c

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
	$(CC) $(CC_FLAGS) $(OBJ) -o $(NAME) $(LIBFT)

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