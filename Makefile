# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: humarque <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/07 14:38:29 by humarque          #+#    #+#              #
#    Updated: 2019/03/13 17:58:57 by mchamayo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_fillit

source = ft_parser.c 

incld = ./includes/

all: $(NAME)

$(NAME):
	
	clang -Wall -Wextra -Werror -I libft/includes -o ft_tetracking.o -c ft_tetracking.c
	clang -Wall -Wextra -Werror -I libft/includes -o ft_stocktetra.o -c ft_stocktetra.c
	clang -Wall -Wextra -Werror -I libft/includes -o ft_parser.o -c ft_parser.c
	clang -Wall -Wextra -Werror -I libft/includes -o ft_check_shape.o -c ft_check_shape.c
	clang -Wall -Wextra -Werror -I libft/includes -o ft_tetraclean.o -c ft_tetraclean.c
	clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
	clang -o $(NAME) ft_stocktetra.o  ft_parser.o ft_check_shape.o main.o ft_tetracking.o ft_tetraclean.o -I libft/includes -L libft/ -lft

clean:
	rm ft_tetracking.o ft_stocktetra.o ft_parser.o ft_check_shape.o ft_tetraclean.o main.o

fclean:
	rm $(NAME)

re: clean fclean all
