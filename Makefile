# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 06:26:04 by drtaili           #+#    #+#              #
#    Updated: 2023/01/04 08:09:01 by drtaili          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = indexing.c operations.c operations_1.c operations_2.c parsing.c push_swap.c sort_3_5.c split.c stack_utils.c utils.c utils_.c

OBJS = $(SRC:.c=.o)

CC = cc

RM = rm -rf

FLAGS = -Wall -Wextra -Werror

all: push_swap

push_swap: $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o push_swap

%.o : %.c push_swap.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) push_swap

re: fclean push_swap

.PHONY = all clean fclean re