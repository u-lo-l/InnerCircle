# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yyoo <yyoo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/17 19:20:57 by dkim2             #+#    #+#              #
#    Updated: 2022/06/16 01:14:00 by dkim2            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES : .c .o

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

NAME = minishell

LIBS = ./LIBFT/libft.a

OBJS_FILES = main.o\
				utils.o \
				read_command.o\
				signal_handler.o\
				env_list.o\
				envlst_to_chararr.o\
				\
				PARSER/token_node.o\
				PARSER/token_list.o\
				PARSER/token_command.o\
				PARSER/token_tree.o\
				PARSER/tokenize_utils.o\
				PARSER/tokenize_check.o\
				PARSER/tokenize_special_char.o\
				PARSER/scanner_function.o\
				\
				BUILTINS/if_builtin.o\
				BUILTINS/echo.o\
				BUILTINS/env.o\
				BUILTINS/env_util.o\
				BUILTINS/export.o\
				BUILTINS/export_utils.o\
				BUILTINS/pwd.o\
				BUILTINS/unset.o\
				BUILTINS/cd.o\
				BUILTINS/exit.o\
				\
				EXECUTE/execute_command.o\
				EXECUTE/execve.o\
				EXECUTE/execve_util.o\
				EXECUTE/inredir.o\
				EXECUTE/outredir.o\
				EXECUTE/pipe.o
OBJS = ${addprefix SRC/, ${OBJS_FILES}}

SRCS = ${OBJS.o=.c}

HEADER_FILES= minishell.h minishell_datastructrue.h

HEADERS = ${addprefix INC/, ${HEADER_FILES}}

all : ${NAME}

clean : 
		@make -C ./LIBFT clean
		${RM} ${OBJS}

fclean : clean
		@make -C ./LIBFT fclean
		${RM} ${NAME}

re : clean all

.PHONY : all clean fclean re

${NAME} : ${OBJS} ${LIBS}
		${CC} -o ${NAME} ${OBJS} ${LIBS} -lreadline

${LIBS} : 
		@make -C ./LIBFT/ all

.c.o :
		${CC} ${CFLAGS} -c $< -o $@
