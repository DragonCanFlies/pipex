# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/16 17:40:13 by latabagl          #+#    #+#              #
#    Updated: 2025/08/25 17:08:04 by latabagl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
FLAGS = -Wall -Wextra -Werror
HEADER = includes/pipex.h
HEADER_BONUS = includes/pipex_bonus.h
SRC = src/pipex.c src/fork_and_exec.c src/set_things_up.c \
	  src/get_args_for_execve.c src/error_handling.c src/pipex_utils.c
SRC_BONUS = bonus/pipex_bonus.c bonus/fork_and_exec_bonus.c \
			bonus/set_things_up_bonus.c bonus/get_args_for_execve_bonus.c \
			bonus/error_handling_bonus.c bonus/pipex_utils_bonus.c
SRC_BONUS_DIR = bonus
SRC_DIR = src
OBJ_DIR = obj
OBJ_BONUS_DIR = obj/bonus
OBJECTS = $(SRC:src/%.c=obj/%.o)
OBJECTS_BONUS = $(SRC_BONUS:bonus/%.c=obj/bonus/%.o)
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I$(LIBFT_DIR)/includes -Iincludes

all: $(NAME)

$(NAME): $(OBJECTS)
		$(MAKE) -C $(LIBFT_DIR)
		$(CC) $(FLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)
		
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
		mkdir -p $(dir $@)
		$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

bonus: $(OBJECTS_BONUS)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(FLAGS) $(OBJECTS_BONUS) $(LIBFT) -o $(NAME)

$(OBJ_BONUS_DIR)/%.o: bonus/%.c $(HEADER_BONUS)
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
		$(MAKE) clean -C $(LIBFT_DIR)
		rm -rf $(OBJECTS) 

fclean: clean
		$(MAKE) fclean -C $(LIBFT_DIR)
		rm -f $(NAME) 
		
.PHONY: all clean fclean bonus re