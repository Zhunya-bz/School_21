SRCS = ft_printf.c ft_printf_utils.c ft_parser.c ft_print_nbr.c ft_print_str.c \
		ft_print_unsig.c ft_print_16.c ft_print_pointer.c

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER = ./libftprintf.h

LIB_DIR = ./libft

.c.o:		
		gcc -c ${CFLAGS} -I ${HEADER} $< -o $(<:.c=.o)

${NAME}:    ${OBJS} ${HEADER}
			@make re -C ${LIB_DIR}
			@cp libft/libft.a ./${NAME}
			@ar rc ${NAME} ${OBJS}

all:    ${NAME}

clean:      
		${RM} ${OBJS}
		@make clean -C ${LIB_DIR}

fclean: clean
		${RM} ${NAME}
		@make fclean -C ${LIB_DIR}

re:     fclean all

.PHONY: fclean clean all re