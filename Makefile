# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/27 14:12:17 by mde-sa--          #+#    #+#              #
#    Updated: 2023/08/16 11:09:15 by mde-sa--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=   push_swap
CC      = 	cc
CFLAGS  =   -Wall -Wextra -Werror
RM      = 	rm -rf
SRC		=	main.c calculate_cost.c calculate_move.c find_targets.c linked_list_func.c moves_push.c moves_rotate.c moves_swap.c process_rotates.c process_stacks.c sort.c validate_create_linked_list.c
OBJS	= 	${SRC:.c=.o}

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

%.o: %.c
	$(CC) -c $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) push_swap

re: fclean
	make all