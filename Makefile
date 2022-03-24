# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oarnoldo <oarnoldo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 13:09:06 by oarnoldo          #+#    #+#              #
#    Updated: 2022/03/24 15:02:56 by oarnoldo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CM = cc

FLAG = -Wall -Wextra -Werror

SRC = push_swap.c src/creat.c src/operations.c src/operations_2.c src/sorting.c src/sort_big_list.c src/bubble_sort.c src/utils_sorting.c \
src/fonction_linked_list_2.c src/fonction_linked_list.c src/ft_putendl_fd.c src/ft_split.c src/auxiliary_functions.c src/operations_3.c src/utils_checking.c

CNVRT = $(SRC:.c=.o)

INCLUDE = push_swap.h

all: $(NAME)

$(NAME): $(CNVRT) $(INCLUDE)
	@$(CM) $(FLAG) $(CNVRT) -o push_swap

%.o : %.c $(INCLUDE)
	@$(CM) $(FLAG) -o $@  -c $<

clean:
	@rm -rf $(CNVRT) $(CNVRTB) push_swap

fclean: clean
	@rm -rf $(NAME)

re: fclean all
