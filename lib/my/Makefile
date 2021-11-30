##
## EPITECH PROJECT, 2021
## BLANK_PROJECT_C
## File description:
## No file there , just an epitech header example
##

SRC = my_printf.c \
	  my_printf_utils.c \
	  my_printf_utils_2.c \
	  my_printf_utils_3.c \
	  my_printf_utils_4.c \
	  my_printf_utils_5.c \
	  my_strlen.c \
	  my_str_contains_c.c \
	  my_strcat_c.c \
	  my_strcat.c \
	  my_strcpy.c \
	  my_strcmp.c \
	  my_putstr.c \
	  my_putnbr.c \
	  my_put_octal.c \
	  my_putchar.c \
	  my_rand.c \
	  my_isdigit.c \
	  my_int_len.c \
	  my_revstr.c \
	  my_convert_base.c \
	  my_itoa.c \
	  my_atoi.c \
	  my_str_lowcase.c \
	  my_str_upcase.c \
	  my_printf_flags.c \
	  my_printf_param.c \
	  my_strncpy.c \
	  my_printf_type.c \
	  my_array_str_sort.c

OBJ = $(SRC:.c=.o)

NAME = lib
CFLAGS += -Werror -Wextra -I./include

$(NAME): $(OBJ)
	ar rc libmy.a *.o
	cp libmy.a ../

all: $(NAME)

fclean:
	make clean
	rm -f ../../my.h
	rm -f ../libmy.a

clean:
	rm -f *.o output

re:
	fclean all
