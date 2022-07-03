.SUFFIXES: .cpp .o

NAME = mi
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98

SRCS = Base.cpp D.cpp F.cpp main.cpp
OBJS = ${SRCS:.cpp=.o}

all : ${NAME}

clean :
	rm -f ${OBJS}

fclean : clean
	rm -r ${NAME}

re : fclean all

.PHONY: all clean fclean re

${NAME} : ${OBJS}
	${CXX} ${OBJS} -o ${NAME}
.cpp.o :
	${CXX} ${CXXFLAGS} -c $< -o $@
