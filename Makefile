##
## EPITECH PROJECT, 2021
## MY_LS
## File description:
## No file there , just an epitech header example
##

MAIN = src/main.c

SRC = src/files.c \
	  src/files_utils.c \
	  src/directory.c \
	  src/directory_utils.c \
	  src/data.c \
	  src/flags.c \
	  src/permissions_utils.c \
	  src/sort.c \
	  src/sort_2.c \
	  src/formating_utils_2.c \
	  src/recursive.c \
	  src/my_ls.c \
	  src/formating.c \
	  src/formating_utils.c \
	  src/time_utils.c

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
	rm -f src/*.o
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.c.gcov

re:
	make fclean
	make

tests_run:
	gcc $(SRC) $(TESTS_SRC) $(SRC_LIB) $(CFLAGS) -lcriterion -o./unit-tests --coverage
	./unit-tests

debug:
	gcc $(SRC) $(SRC_LIB) -o./$(NAME) -g

valgrind:
	gcc $(SRC) $(SRC_LIB) -o./$(NAME) -g3
	valgrind ./$(NAME)

gdb:
	gcc $(SRC) $(SRC_LIB) -o./$(NAME) -g
	gdb ./$(NAME)
