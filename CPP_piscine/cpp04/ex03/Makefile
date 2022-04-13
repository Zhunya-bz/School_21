SRCS	=	main.cpp AMateria.cpp Character.cpp Ice.cpp Cure.cpp MateriaSource.cpp

OBJS	=	${SRCS:.cpp=.o}

NAME = Materia

HEADER =  AMateria.hpp Character.hpp ICharacter.hpp Ice.hpp Cure.hpp MateriaSource.hpp IMateriaSource.hpp

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