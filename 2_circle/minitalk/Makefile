.SUFFIXES : .c .o

SERVER = server
CLIENT = client

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

UTILS_O = utils.o
SERVER_O = server.o
CLIENT_O = client.o

UTILS_C = utils.c
SERVER_C = server.c
CLIENT_C = client.c

UTILS_B_O = bonus/utils_bonus.o
SERVER_B_O = bonus/server_bonus.o
CLIENT_B_O = bonus/client_bonus.o

UTILS_B_C = bonus/utils_bonus.c
SERVER_B_C = bonus/server_bonus.c
CLIENT_B_C = bonus/client_bonus.c

ifdef WITH_BONUS
	SRV_O = $(UTILS_B_O) $(SERVER_B_O)
	CLI_O = $(UTILS_B_O) $(CLIENT_B_O)
else
	SRV_O = $(UTILS_O) $(SERVER_O)
	CLI_O = $(UTILS_O) $(CLIENT_O)
endif


all : srv cli

bonus :
	@make WITH_BONUS=1 all

srv : $(SERVER)

cli : $(CLIENT)

clean :
	$(RM) $(UTILS_O) $(CLIENT_O) $(SERVER_O) $(UTILS_B_O) $(CLIENT_B_O) $(SERVER_B_O)

fclean : clean
	$(RM) $(SERVER) $(CLIENT) $(SERVER_B) $(CLIENT_B)

re : fclean all

.PHONY : all s c clean fclean re bonus

$(SERVER) : $(SRV_O)
	$(CC) -o $@ $^

$(CLIENT) : $(CLI_O)
	$(CC) -o $@ $^

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@
