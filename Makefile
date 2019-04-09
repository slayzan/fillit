# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: humarque <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/08 14:15:22 by humarque          #+#    #+#              #
#    Updated: 2019/04/09 12:01:43 by mchamayo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc

SRC_PATH = ./src/
OBJ_PATH = ./obj/
LIB_PATH = ./lib/
INC_PATH = ./include/ $(LIB_PATH)libft/include/

GCC_FLGS = -Werror -Wextra -Wall

SRC_NAME = main.c ft_check_shape.c ft_coord.c ft_parser.c ft_printresult.c \
		   ft_solver.c ft_stocklist.c ft_stocktetra.c

OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = libft

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(addprefix -L$(LIB_PATH),$(LIB_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_PATH)libft
	$(CC) $(GCC_FLGS) $(LIB) -lft $(INC) $(OBJ) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(GCC_FLGS) $(INC) -o $@ -c $<

clean:
	rm -fv $(OBJ)

fclean: clean
	make -C $(LIB_PATH)libft fclean
	rm -fv $(NAME)

re: fclean all
