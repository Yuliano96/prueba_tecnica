CC= cc -g
FLAGS = -Wall -Wextra -Werror -lpthread

NAME = exe
SRC = list.c util.c main.c thread.c validate.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)
