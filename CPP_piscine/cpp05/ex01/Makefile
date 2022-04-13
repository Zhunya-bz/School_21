SRCS	=	main.cpp  Bureaucrat.cpp Form.cpp

OBJS	=	${SRCS:.cpp=.o}

NAME =		Bureaucrat

HEADER =	Bureaucrat.hpp Form.hpp

CXX = clang++

RM = rm -fr

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