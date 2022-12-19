# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esafar <esafar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 13:23:13 by esafar            #+#    #+#              #
#    Updated: 2022/12/19 13:38:55 by esafar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_containers

SRC = containers/vector_test.cpp \
	  containers/stack_test.cpp

OBJ = $(SRC:.cpp=.o)

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) vector stack

re: fclean all

vector: $(OBJ)
	$(CC) $(CFLAGS) -o vector containers/vector_test.o

stack: $(OBJ)
	$(CC) $(CFLAGS) -o stack containers/stack_test.o

.PHONY: all clean fclean re
