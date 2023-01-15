# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 06:26:04 by drtaili           #+#    #+#              #
#    Updated: 2023/01/15 22:12:36 by drtaili          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = indexing.c operations.c operations_1.c operations_2.c parsing.c push_swap.c sort2_3_4_5.c split.c stack_utils.c utils.c utils_.c sort_100.c sort_over_100.c 
SRC_bonus = get_next_line_utils.c get_next_line.c checker_bonus.c indexing.c parsing.c operations.c operations_1.c operations_2.c split.c stack_utils.c utils.c utils_.c 

OBJS = $(SRC:.c=.o)
OBJS_bonus = $(SRC_bonus:.c=.o)

CC = cc

RM = rm -rf

FLAGS = -Wall -Wextra -Werror

all: push_swap

push_swap : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o push_swap

bonus : $(OBJS_bonus)
	$(CC) $(FLAGS) $(OBJS_bonus) -o checker

%.o : %.c push_swap.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS_bonus)

fclean: clean
	$(RM) push_swap checker

re: fclean push_swap bonus

.PHONY = all clean fclean re