# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/27 14:12:17 by mde-sa--          #+#    #+#              #
#    Updated: 2023/07/27 14:51:51 by mde-sa--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = 	cc
RM      = 	rm -rf
OBJS	= 	${SRC:.c=.o}
SRC		=	${wildcard *.c}

teste:
	@make all -s
	@make clean -s

all: $(OBJS)
	@$(CC) $(SRC)

%.o: %.c
	@$(CC) -c $<

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) a.out

re: fclean
	@$(MAKE) all