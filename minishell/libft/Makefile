SRCS =	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c		\
		ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c		\
		ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c		\
		ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strdup.c ft_calloc.c		\
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c			\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strcmp.c

BONUS =	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c		\
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_strndup.c lib_utils.c	\
		get_next_line.c ft_how_many_char.c 

SRCS_DIR = srcs/

OBJS = ${addprefix ${SRCS_DIR}, ${SRCS:.c=.o}}

BONUS_OBJS = ${addprefix ${SRCS_DIR}, ${BONUS:.c=.o}}

NAME = libft.a

HEADER = ${addprefix ${SRCS_DIR}, libft.h}

CC = gcc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror

# COLORS

GREEN	= \033[0;32m
YELO	= \033[0;33m
BLUE	= \033[0;34m
NEW		= \033[0;35m
SHALLOW = \033[0m

# END COLORS

.PHONY: all clean fclean re norm

%.o:%.c		${HEADER}
			@${CC} ${CFLAGS} -c $< -o ${<:.c=.o} 

${NAME}:	${OBJS} ${BONUS_OBJS} ${HEADER}
			@ar rcs ${NAME} ${OBJS} ${BONUS_OBJS}
			@echo "${GREEN}${NAME} ready!${SHALLOW}"
			
all:		${NAME} 

norm:
			@echo "${GREEN}|-----Chek NORMs!-----|${NEW}"
			@norminette ./
			@echo "${GREEN}|-----Chek ended!-----|${SHALLOW}"

clean:		
			@${RM} ${OBJS} ${BONUS_OBJS}
			@echo "${BLUE}${NAME} clean done!${SHALLOW}"

fclean:		
			@${RM} ${OBJS} ${BONUS_OBJS} 
			@${RM} ${NAME}
			@echo "${YELO}${NAME} fclean done!${SHALLOW}"

re:			fclean all 