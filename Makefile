# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/04 00:01:35 by jremarqu          #+#    #+#              #
#    Updated: 2019/08/05 03:20:36 by pjeraldi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = fillit

LIBFT = ./Libft/

SRC      = map.c              \
           empty_file.c       \
           other.c            \
           helper.c           \
           four_line.c        \
           valid_tetra.c      \
           tetramins_helper.c \
           tetramins.c        \
           algoritm_final.c   \
           main.c             \

OBJ = $(SRC:.c=.o)

INCLUDE = header.h

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@gcc -Wall -Werror -Wextra -o $(NAME) $(OBJ) -lm -L $(LIBFT) -lft

$(OBJ): $(SRC)
	@gcc -Wall -Werror -Wextra -c $(SRC)

lib_refresh:
	@make -C $(LIBFT) re

clean:
	@/bin/rm -rf $(OBJ)
	@make clean -C $(LIBFT)

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

