SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS = ${SRCS:.c=.o}
NAME = libft.a
INCL = includes
CFLAGS = -Wall -Wextra -Werror

.c.o: cc ${CFLAGS} -c $< -o ${:.c=.o} -I ${INCL}

${NAME}: ${OBJS}
		ar rc ${NAME} ${OBJS}
		ranlib ${NAME}

all : ${NAME}

clean:
		rm -rf ${OBJS}

fclean: clean
		rm -rf ${NAME}

re: fclean all

.PHONY: all re fclean clean .c.o