SRCS =      func.c func2.c func3.c main.c

OBJS = ${SRCS:.c=.o}

NAME = bsq

RM = rm -f

CFLAG = -Wall -Wextra -Werror

HEADER = ./bsq.h

.c.o:		
		gcc -c ${CFLAG} -I ${HEADER} $< -o $(<:.c=.o)

${NAME}:    ${OBJS}
		gcc -o ${NAME} ${OBJS}

all:    ${NAME}

clean:      
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re:     fclean all

.PHONY: fclean clean all re