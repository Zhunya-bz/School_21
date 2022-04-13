SRCS	=	main.cpp  Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp \
			PresidentialPardonForm.cpp Intern.cpp

OBJS	=	${SRCS:.cpp=.o}

NAME =		Bureaucrat

HEADER =	Bureaucrat.hpp Form.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp \
			PresidentialPardonForm.hpp Intern.hpp

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
			@${RM} ${OBJS} *_shrubbery

fclean:		clean
			@${RM} ${NAME} *_shrubbery

re:			fclean all