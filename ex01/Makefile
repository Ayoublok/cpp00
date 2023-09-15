# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayylaaba <ayylaaba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 15:40:59 by ayylaaba          #+#    #+#              #
#    Updated: 2023/09/14 13:20:10 by ayylaaba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = phonebook

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror

SRC =  phonebook.cpp\

OBJ = ${SRC:.cpp=.o}

all : ${NAME}

${NAME} : ${OBJ}
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -f ${OBJ}

fclean : clean
	rm -f ${NAME}

re : fclean all
