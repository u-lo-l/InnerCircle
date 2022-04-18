.SUFFIXES : .c .o

CC = gcc
CFLAGS = -Wall -Werror -Wextra 
RM = rm -f

NAME  = philo

OBJS = utils.o preprocess.o philosopher.o main.o

SRCS = $(OBJS.o = .c)

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $(NAME) -lpthread -g

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@