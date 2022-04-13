SRCS	=	main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp

OBJS	=	${SRCS:.cpp=.o}

NAME = AnimalBrain

HEADER = Animal.hpp Cat.hpp Dog.hpp Brain.hpp

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