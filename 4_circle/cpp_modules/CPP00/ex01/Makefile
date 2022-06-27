# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/23 14:53:30 by dkim2             #+#    #+#              #
#    Updated: 2022/06/27 11:42:41 by dkim2            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES: .cpp .o

NAME = phonebook

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SRCS = Phonebook.cpp Contact.cpp main.cpp
OBJS = ${SRCS:.cpp=.o}

all : ${NAME}

clean :
	${RM} ${OBJS}

fclean :
	${RM} ${OBJS} ${NAME}

re : fclean all

.PHONY : all clean fclean re

${NAME} : ${OBJS}
	${CXX} ${OBJS} -o ${NAME}
.cpp.o:
	${CXX} ${CXXFLAGS} -c $< -o $@
