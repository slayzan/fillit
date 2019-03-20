NAME = test_fillit

source = main.c

objets = main.o

flags = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	clang $(flags) -I libft/includes -o $(source) -c $(objets)
	clang -o $(NAME) $(objets)  -I ../libft/includes -L ../libft/ -lft

clean:
	rm $(objets)

fclean:
	rm $(NAME)

re: clean fclean all
