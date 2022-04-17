.SUFFIXES : .c .o

CC = gcc
CFLAGS = -Wall -Werror -Wextra 
RM = rm -f

TARGET  = philo

OBJS = dining.o \
		main.o \
		time.o \
		utils.o

SRCS = $(OBJS.o = .c)

all : $(TARGET)

clean :
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(TARGET)

re : fclean all

.PHONY : all clean fclean re

$(TARGET) : $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) -lpthread -g

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@