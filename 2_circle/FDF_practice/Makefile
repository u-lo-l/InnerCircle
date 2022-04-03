.SUFFIXES : .c .o

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

TARGET  = test

#OBJS = MOVEIMG/move_image.o \
#		MOVEIMG/events.o \
#		MOVEIMG/draw.o
OBJS = mlx_leak_test.o

SRCS = $(OBJS.o=.c)

all : $(TARGET)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(TARGET)

re : fclean all

.PHONY : all clean fclean re

$(TARGET) : $(OBJS)
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib \
	-Imlx_linux -lXext -lX11 -lm -lz -o $(TARGET) -lm

.c.o :
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@ -g
