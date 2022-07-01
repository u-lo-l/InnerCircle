# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/28 13:48:11 by dkim2             #+#    #+#              #
#    Updated: 2022/07/01 19:25:47 by dkim2            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES: .cpp .o

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = harl
SRCS = main.cpp Harl.cpp
OBJS = ${SRCS:.cpp=.o}

all : ${NAME}

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}
	
re : fclean all

${NAME} : ${OBJS}
	${CXX} ${OBJS} -o ${NAME}

.cpp.o :
	${CXX} ${CXXFLAGS} -c $< -o $@
