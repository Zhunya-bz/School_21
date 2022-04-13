SRCS	=	main.cpp Span.cpp

OBJS	=	${SRCS:.cpp=.o}

NAME =		containers

HEADER =	Span.hpp

CXX = clang++

RM = rm -fr

CPPFLAGS = -Wall -Wextra -Werror


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