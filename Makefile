# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: humarque <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/07 14:38:29 by humarque          #+#    #+#              #
#    Updated: 2019/04/06 14:02:31 by mchamayo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_fillit

source = ft_parser.c

flag = -Wall -Wextra -Werror

incld = ./includes/

all: $(NAME)

$(NAME):
	
	clang -I libft/includes -o main.o -c main.c
	clang -I libft/includes -o ft_parser.o -c ft_parser.c
	clang -I libft/includes -o ft_printresult.o -c ft_printresult.c
	clang -I libft/includes -o ft_solver.o -c ft_solver.c
	clang -I libft/includes -o ft_stocktetra.o -c ft_stocktetra.c
	clang -I libft/includes -o ft_coord.o -c ft_coord.c
	clang -I libft/includes -o ft_stocklist.o -c ft_stocklist.c
	clang -o $(NAME) main.o ft_parser.o ft_printresult.o ft_solver.o ft_stocktetra.o ft_coord.o ft_stocklist.o -I libft/includes -L libft/ -lft

clean:
	rm main.o ft_parser.o ft_printresult.o ft_solver.o ft_stocktetra.o ft_coord.o ft_stocklist.o

fclean:
	rm $(NAME)

re: clean fclean all
