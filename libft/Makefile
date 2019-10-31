NAME = libft.a

OBJ = $(patsubst %.c, %.o, $(wildcard *.c))

FLAGS = -Wall -Wextra -Werror

INC = libft.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(INC)
	gcc $(FLAGS) -c $< -o $@ -I $(INC)

clean:
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
