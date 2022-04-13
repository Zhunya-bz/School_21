SRCS = doop.c ft_atoi.c ft_putstr.c ft_putnbr.c functions.c
OBJS = ${SRCS:.c=.o}
NAME = do-op
CFLAGS = -Wall -Wextra -Werror

.c.o: cc ${CFLAGS} -c $< -o ${:.c=.o}

${NAME}: ${OBJS}
			gcc -o ${NAME} ${OBJS}

all : ${NAME}

clean:
		rm -f ${OBJS}

fclean: clean
		rm -f ${NAME}

re: fclean all