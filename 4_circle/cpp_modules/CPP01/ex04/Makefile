# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/28 13:48:11 by dkim2             #+#    #+#              #
#    Updated: 2022/07/04 15:04:15 by dkim2            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES: .cpp .o

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

NAME = no_more_sed
SRC = main.cpp
OBJ = ${SRC:.cpp=.o}

all : ${NAME}

clean :
	rm -f ${OBJ}

fclean : clean
	rm -f ${NAME}
	
re : fclean all

${NAME} : ${OBJ}
	${CXX} ${OBJ} -o ${NAME}

.cpp.o :
	${CXX} ${CXXFLAGS} -c $< -o $@