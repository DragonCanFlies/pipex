# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: latabagl <latabagl@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/16 17:40:13 by latabagl          #+#    #+#              #
#    Updated: 2025/07/16 17:46:55 by latabagl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
FLAGS = -Wall -Wextra -Werror
HEADER = pipex.h
CFILES = pipex.c fork_and_exec.c set_things_up.c get_args_for_execve.c split.c 
OBJECTS = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
		$(CC) $(FLAGS) $(OBJECTS) -o $(NAME)

%.o: %.c $(HEADER)
		$(CC) $(FLAGS) -c $< -o $@

clean:
		rm -f $(OBJECTS)

fclean: clean
		rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re