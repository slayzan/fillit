# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: humarque <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/20 14:37:44 by humarque          #+#    #+#              #
#    Updated: 2019/03/20 14:37:49 by humarque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
