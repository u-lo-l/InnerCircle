# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/27 14:19:03 by dkim2             #+#    #+#              #
#    Updated: 2022/07/04 15:04:05 by dkim2            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES: .cpp .o

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic

NAME = brain
SRC = main.cpp
OBJ = main.o

all : ${NAME}

clean :
	rm -f ${OBJ}

fclean : clean
	rm -rf ${NAME}

re	: fclean all

.PHONY: all clean fclean re

${NAME} : ${OBJ}
	$(CXX) ${OBJ} -o ${NAME}

.cpp.o :
	${CXX} ${CXXFLAGS} -c $< -o $@