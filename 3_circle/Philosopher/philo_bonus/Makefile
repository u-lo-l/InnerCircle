.SUFFIXES : .c .o

CC = gcc
CFLAGS = -Wall -Werror -Wextra 
RM = rm -f

NAME  = philo_bonus

OBJS = utils_bonus.o preprocess_bonus.o philosopher_bonus.o main_bonus.o philo_process.o

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