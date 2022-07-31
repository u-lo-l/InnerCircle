# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkim2 <dkim2@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 19:49:19 by dkim2             #+#    #+#              #
#    Updated: 2022/07/31 22:48:16 by dkim2            ###   ########.fr        #
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

OBJ_FILES = COLOR/color.o \
			MLX/mlx_event.o MLX/mlx_part.o\
			PARSE/camera.o PARSE/light.o PARSE/object.o PARSE/read_file.o \
			RAY/ray.o RAY/object_intersect.o RAY/cylinder_intersection.o RAY/get_normal_vector.o\
			SCENE/print_scene.o SCENE/print_scene2.o SCENE/scene_utils.o SCENE/scene1.o SCENE/scene2.o \
			main.o

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
ifeq (${UNAME_S},Linux)
	${CC} ${OBJS} ${LIBS} ${LIBV} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o ${NAME}
else
	${CC} ${OBJS} ${LIBS} ${LIBV} -Lmlx -lmlx -framework OpenGL -framework AppKit -lm -o ${NAME}
endif

${LIBS} :
	@make -C ./LIBFT all
${LIBV} :
	@make -C ./Libft_vector all

.c.o :
ifeq (${UNAME_S},Linux)
	${CC} ${CFLAGS} -I/usr/include -Imlx_linux -O3 -c $< -o $@
else
	${CC} ${CFLAGS} -Imlx -c $< -o $@
endif
