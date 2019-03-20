# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: humarque <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/20 14:37:44 by mchamayo          #+#    #+#              #
#    Updated: 2019/03/20 14:37:49 by humarque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_fillit

source = main.c ft_parser.c ft_stocktab.c

objets = main.o ft_parser.o ft_stocktab.o

flags = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	clang $(flags) -I libft/includes -o main.o -c main.c
	clang $(flags) -I libft/includes -o ft_parser.o -c ft_parser.c
	clang $(flags) -I libft/includes -o ft_stocktab.o -c ft_stocktab.c
	clang -o $(NAME) $(objets)  -I ../libft/includes -L ../libft/ -lft

clean:
	rm $(objets)

fclean:
	rm $(NAME)

re: clean fclean all
