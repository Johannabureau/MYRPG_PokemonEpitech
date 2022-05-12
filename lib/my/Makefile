##
## EPITECH PROJECT, 2021
## makefile
## File description:
## lib creation
##
CFLAGS = -Wall -Wextra -Wshadow
CPPFLAGS = -I ./include -g

SRC = 	my_swap.c \
		my_isneg.c \
		my_putstr.c \
		my_revstr.c \
		my_getnbr.c \
		my_strcat.c \
		my_strcmp.c \
		my_strcpy.c \
		my_strlen.c \
		my_printf.c \
		str_count.c \
		my_put_nbr.c \
		my_strncat.c \
		my_strncmp.c \
		my_putchar.c \
		my_strncpy.c \
		my_freetab.c \
		str_to_word.c \
		my_is_prime.c \
		my_str_isnum.c \
		my_str_isalphanum.c \
		my_strupcase.c \
		my_move_char.c \
		my_strlowcase.c \
		my_str_islower.c \
		my_str_isalpha.c \
		my_print_alpha.c \
		my_str_isupper.c \
		my_print_digits.c \
		my_convert_base.c \
		my_print_revalpha.c \
		my_find_prime_sup.c \
		my_str_isprintable.c \
		my_compute_square_root.c \

OBJ = $(SRC:.c=.o)

NAME = libmy.a

all: NAME

NAME: $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f *.o
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean NAME
