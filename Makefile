# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: humarque <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/07 14:38:29 by humarque          #+#    #+#              #
#    Updated: 2019/02/27 16:35:20 by mchamayo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_fillit

source = ft_parser.c 

incld = ./includes/

all: $(NAME)

$(NAME):
	
	clang -Wall -Wextra -Werror -I libft/includes -o ft_printtab.o -c ft_printtab.c
	clang -Wall -Wextra -Werror -I libft/includes -o ft_stocktetra.o -c ft_stocktetra.c
	clang -Wall -Wextra -Werror -I libft/includes -o ft_parser.o -c ft_parser.c
	clang -Wall -Wextra -Werror -I libft/includes -o ft_check_shape.o -c ft_check_shape.c
	clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
	clang -o $(NAME) ft_stocktetra.o ft_printtab.o ft_parser.o ft_check_shape.o main.o -I libft/includes -L libft/ -lft

clean:
	rm ft_printtab.o ft_stocktetra.o ft_parser.o ft_check_shape.o main.o 

fclean:
	rm $(NAME)

re: clean fclean all
