# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/16 17:40:13 by latabagl          #+#    #+#              #
#    Updated: 2025/08/16 20:08:04 by latabagl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
FLAGS = -Wall -Wextra -Werror
HEADER = includes/pipex.h
SRC = pipex.c src/fork_and_exec.c src/set_things_up.c \
	  src/get_args_for_execve.c src/error_handling.c src/pipex_utils.c
SRC_DIR = src
OBJ_DIR = obj
OBJECTS = $(SRC:src/%.c=obj/%.o)
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I$(LIBFT_DIR) -Iincludes

all: $(NAME)

$(NAME): $(OBJECTS)
		$(MAKE) -C $(LIBFT_DIR)
		$(CC) $(FLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)
		
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
		mkdir -p $(dir $@)
		$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
		$(MAKE) clean -C $(LIBFT_DIR)
		rm -rf $(OBJECTS) 

fclean: clean
		$(MAKE) fclean -C $(LIBFT_DIR)
		rm -f $(NAME) 
		
.PHONY: all clean fclean re