# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: humarque <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/07 14:38:29 by humarque          #+#    #+#              #
#    Updated: 2019/02/13 15:00:14 by mchamayo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test

source = ft_parser.c 

incld = ./includes/

all: $(NAME)

$(NAME):
	
	clang -Wall -Wextra -Werror -I libft/includes -o ft_stocktetra.o -c ft_stocktetra.c
	clang -Wall -Wextra -Werror -I libft/includes -o ft_parser.o -c ft_parser.c
	clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
	clang -o test ft_stocktetra.o ft_parser.o main.o -I libft/includes -L libft/ -lft
fclean:
	rm $(NAME)

re:fclean all