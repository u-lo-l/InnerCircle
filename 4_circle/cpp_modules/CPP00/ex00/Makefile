# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkim2 <dkim2@student.42Seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 15:09:45 by dkim2             #+#    #+#              #
#    Updated: 2022/07/04 15:00:19 by dkim2            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXEX: .cpp .o

NAME = megaphone

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -pedantic -std=c++98
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
	${CXX} ${OBJS} -o ${NAME}

.cpp.o :
	${CXX} ${CXXFLAGS} -c $< -o $@
