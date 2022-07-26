# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 19:49:19 by dkim2             #+#    #+#              #
#    Updated: 2022/07/26 14:52:39 by dkim2            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES: .c .o

UNAME_S = ${shell uname -s}

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

NAME = miniRT
LIBS = ./LIBFT/libft.a
LIBV = ./Libft_vector/libvector.a

OBJ_FILES = main.o read_file.o\
			object.o light.o camera.o \
			scene1.o scene2.o \
			scene_utils.o print_scene.o print_scene2.o \
			\
			mlx_part.o mlx_event.o \
			\
			object_intersect.o
OBJS = ${addprefix SRC/, ${OBJ_FILES}}

SRCS = ${OBJS:.o = .c}




all : ${NAME}

clean :
	@make -C ./LIBFT clean
	@make -C ./Libft_vector clean
	${RM} ${OBJS}

fclean : clean
	@make -C ./LIBFT fclean
	@make -C ./Libft_vector fclean
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re

${NAME} : ${OBJS} ${LIBS} ${LIBV}
ifeq ( $(UNAME_S), "Darwin" )
		shell echo "HI"
		${CC} ${OBJS} -o ${NAME} ${LIBS} ${LIBV} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz 
else
		${CC} ${OBJS} -o ${NAME} ${LIBS} ${LIBV} -Lmlx -lmlx -framework OpenGL -framework AppKit -lm
endif

${LIBS} :
	@make -C ./LIBFT all
${LIBV} :
	@make -C ./Libft_vector all

.c.o :
ifeq ( ${UNAME_S}, "Darwin" )
		${CC} ${CFLAGS} -I/usr/include -Imlx_linux -O3 -c $< -o $@
else
		${CC} ${CFLAGS} -Imlx -c $< -o $@
endif
