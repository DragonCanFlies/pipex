NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes
HEADER = includes/libft.h includes/printf.h includes/gnl.h
CFILES = src/gnl/get_next_line_utils.c \
		src/gnl/get_next_line.c \
		src/printf/base10tohexa.c src/printf/find_specifier.c \
		src/printf/ft_printchar.c src/printf/ft_printf.c \
		src/printf/ft_printint.c src/printf/ft_printstr.c \
		src/printf/ft_printaddress.c src/printf/ft_print_hex.c \
		src/printf/ft_print_uppercase_str.c src/printf/ft_print_unsigned.c \
		src/libft/ft_atoi.c src/libft/ft_isalnum.c src/libft/ft_isdigit.c \
		src/libft/ft_memchr.c src/libft/ft_memmove.c src/libft/ft_putendl_fd.c \
		src/libft/ft_split.c src/libft/ft_striteri.c \
		src/libft/ft_strlcpy.c src/libft/ft_strncmp.c src/libft/ft_strtrim.c \
		src/libft/ft_toupper.c src/libft/ft_bzero.c src/libft/ft_isalpha.c \
		src/libft/ft_isprint.c src/libft/ft_memcmp.c src/libft/ft_memset.c \
		src/libft/ft_putnbr_fd.c src/libft/ft_strchr.c src/libft/ft_strjoin.c \
		src/libft/ft_strlen.c src/libft/ft_strnstr.c src/libft/ft_substr.c \
		src/libft/ft_calloc.c src/libft/ft_isascii.c src/libft/ft_itoa.c \
		src/libft/ft_memcpy.c src/libft/ft_putchar_fd.c \
		src/libft/ft_putstr_fd.c src/libft/ft_strdup.c \
		src/libft/ft_strlcat.c src/libft/ft_strmapi.c src/libft/ft_strrchr.c \
		src/libft/ft_tolower.c
OBJECTS = $(CFILES:.c=.o)
INCLUDES = -Iincludes

all: $(NAME)

$(NAME): $(OBJECTS)
		ar rcs $(NAME) $(OBJECTS)

%.o: %.c $(HEADER)
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
		rm -rf $(OBJECTS) 

fclean: clean
		rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re