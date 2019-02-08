# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: humarque <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/07 14:38:29 by humarque          #+#    #+#              #
#    Updated: 2019/02/07 14:48:21 by humarque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test

source = ft_parser.c 

incld = ./includes/

all: $(NAME)

$(NAME):
	
	clang -Wall -Wextra -Werror -I libft/includes -o ft_parser.o -c ft_parser.c
	clang -o test ft_parser.o -I libft/includes -L libft/ -lft
fclean:
	rm $(NAME)

re:fclean all
