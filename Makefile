##
## EPITECH PROJECT, 2021
## MY_LS
## File description:
## No file there , just an epitech header example
##

MAIN = main.c

SRC =

TESTS =

OBJ = $(MAIN:.c=.o) $(SRC:.c=.o)

NAME = my_ls
SRC_LIB = -Llib -lmy
CFLAGS += -Wextra -Iinclude -g3

$(NAME): $(OBJ)
	cd lib/my && make
	gcc $(OBJ) $(SRC_LIB) -o./$(NAME) -g3

all: $(NAME)

fclean:
	cd lib/my && make fclean
	make clean
	rm -f $(NAME)
	rm -f unit-tests

clean:
	rm -f *.o
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.c.gcov

re:
	make fclean
	make

tests_run:
	gcc $(TESTED_SRC) $(TESTS_SRC) $(SRC_LIB) $(CFLAGS) -lcriterion -o./unit-tests --coverage
	./unit-tests

debug:
	gcc $(SRC) $(SRC_LIB) -o./$(NAME) -g

valgrind:
	gcc $(SRC) $(SRC_LIB) -o./$(NAME) -g3
	valgrind ./$(NAME)

gdb:
	gcc $(SRC) $(SRC_LIB) -o./$(NAME) -g
	gdb ./$(NAME)
