# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/03 00:53:56 by dkim2             #+#    #+#              #
#    Updated: 2022/07/18 20:18:00 by dkim2            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES: .cpp .o

NAME = fragtrap
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp ClapTrap.cpp FragTrap.cpp ScavTrap.cpp
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