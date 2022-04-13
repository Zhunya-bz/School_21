SRCS	=	Zombie.cpp main.cpp ZombieHorde.cpp

OBJS	=	${SRCS:.cpp=.o}

NAME = Zombie

HEADER = Zombie.hpp

CXX = clang++

RM = rm -f

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

.PHONY: all clean fclean re

.cpp.o:
			${CXX} ${CPPFLAGS} -c $< -o $@

all:		${NAME}

${NAME}:	${OBJS} ${HEADER}
			@${CXX} ${CPPFLAGC} -o ${NAME} ${OBJS}

clean:
			@${RM} ${OBJS}

fclean:		clean
			@${RM} ${NAME}

re:			fclean all