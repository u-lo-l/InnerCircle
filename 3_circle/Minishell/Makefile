# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/17 19:20:57 by dkim2             #+#    #+#              #
#    Updated: 2022/05/18 15:59:47 by dkim2            ###   ########.fr        #
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

all : ${NAME}

clean : 
		${RM} ${OBJS}

fclean : clean
		${RM} ${NAME}

re : clean all

.PHONY : all clean fclean re

${NAME} : ${OBJS}
		${CC} ${OBJS} -o ${NAME} -lreadline \
		-L /Users/dkim2/.brew/opt/readline/lib \
		-I /Users/dkim2/.brew/opt/readline/include

.c.o :
		${CC} ${CFLAGS} -c $< -o $@
