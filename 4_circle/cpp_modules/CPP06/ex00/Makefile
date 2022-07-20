# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/10 00:20:11 by dkim2             #+#    #+#              #
#    Updated: 2022/07/20 19:09:33 by dkim2            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES: .cpp .o

NAME = conversion
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp printData.cpp stringToNum.cpp
OBJS = ${SRCS:.cpp=.o}

all : ${NAME}

clean :
	rm -f ${OBJS}

fclean : clean
	rm -r ${NAME}

re : fclean all

.PHONY: all clean fclean re

${NAME} : ${OBJS}
	${CXX} ${OBJS} -o ${NAME}
.cpp.o :
	${CXX} ${CXXFLAGS} -c $< -o $@