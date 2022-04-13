SRCS	=	main_sub.cpp

OBJS	=	${SRCS:.cpp=.o}

NAME =		template

HEADER =	iter.hpp

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