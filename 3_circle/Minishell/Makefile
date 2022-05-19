# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/17 19:20:57 by dkim2             #+#    #+#              #
#    Updated: 2022/05/19 16:07:22 by dkim2            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES : .c .o

CC = cc
CFLAGS = -Wall -Werror -Wextra

NAME = minishell

OBJS_FILES = read_command.o\
				main.o\
				signal_handler.o
OBJS = ${addprefix SRC/, ${OBJS_FILES}}

SRCS = ${OBJS.o=.c}

HEADERS = INC/minishell.h INC/minishell_datastructrue.h

all : ${NAME}

clean : 
		${RM} ${OBJS}

fclean : clean
		${RM} ${NAME}

re : clean all

.PHONY : all clean fclean re

${NAME} : ${OBJS}
		${CC} -o ${NAME} ${OBJS} -lreadline \
		-L/Users/dkim2/.brew/Cellar/readline/8.1.2/lib \
		-I/Users/dkim2/.brew/Cellar/readline/8.1.2/include
.c.o : ${HEADERS}
		${CC} ${CFLAGS} -c $< -o $@ \
		-I/Users/dkim2/.brew/Cellar/readline/8.1.2/include
