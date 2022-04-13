SRCS	= main.cpp

OBJS	=	${SRCS:.cpp=.o}

NAME = replace

HEADER =

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
			@${RM} ${OBJS} *.replace

fclean:		clean
			@${RM} ${NAME} *.replace

re:			fclean all