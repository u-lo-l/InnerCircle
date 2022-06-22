# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkim2 <dkim2@student.42Seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 15:09:45 by dkim2             #+#    #+#              #
#    Updated: 2022/06/22 15:27:30 by dkim2            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

OBJS = megaphone.o
SRCS = ${OBJS:.o=.cpp}

all : ${NAME}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean re

${NAME} : ${OBJS}
	${CXX} ${CXXFLAGS} -o ${NAME} ${OBJS}
