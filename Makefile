# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/27 14:12:17 by mde-sa--          #+#    #+#              #
#    Updated: 2023/08/16 12:13:00 by mde-sa--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=   push_swap

CC      = 	cc

CFLAGS  =   -Wall -Wextra -Werror -g

SRCDIR	=	src

INCDIR	=   includes

SRC		=	main.c calculate_cost.c calculate_move.c find_targets.c linked_list_func.c \
			moves_push.c moves_rotate.c moves_swap.c process_rotates.c process_stacks.c \
			sort.c validate_create_linked_list.c

OBJS	= 	$(addprefix $(SRCDIR)/, $(SRC:.c=.o))

RM      = 	rm -rf


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -I $(INCDIR) -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re