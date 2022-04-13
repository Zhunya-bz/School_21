SRCS = ft_cat.c ft_putstr.c ft_putchar.c
OBJS = ${SRCS:.c=.o}
NAME = ft_cat
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