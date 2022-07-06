.SUFFIXES : .c .o

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

NAME  = miniRT

OBJ_M_DIR = ./SRCS/
OBJS_FILE = main

OBJS_M = ${addprefix ${OBJ_M_DIR}, ${addsuffix .o, ${OBJS_FILE}}}

SRCS_M = ${OBJS_M.o=.c}

all : ${NAME}

clean :
	${RM} ${OBJS_M} ${OBJS_B}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re bonus

${NAME} : ${OBJS}
	${CC} ${OBJS} -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}
.c.o :
	${CC} ${CFLAGS} -Wall -Wextra -Werror -Imlx -c $< -o $@
