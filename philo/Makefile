# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 10:45:33 by jgasparo          #+#    #+#              #
#    Updated: 2024/03/19 15:27:43 by jgasparo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = sources/main.c \
		sources/ft_atol.c \
		sources/threads.c \
		sources/time.c \
		sources/init.c \
		sources/routine.c \
		sources/write.c \
		sources/error.c \
		sources/dead.c \
		sources/clean.c \
		 
OBJ = $(SRC:.c=.o)
LIBS = -lpthread 
TEST = -fsanitize=thread -g
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

test: 
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(TEST) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
