SRCS	=	minishell.c minishell_utils.c parser.c proc_redirects.c pars_dollar.c	\
			here_doc.c cmd.c builtins.c signals.c own_progc.c builtins_utils.c		\
			cmd_utils.c cmd_multiple.c pipes_redir.c export.c free_clear.c cd.c		\
			exit.c echo.c

SRCS_DIR = srcs/

OBJS	=	${addprefix ${SRCS_DIR}, ${SRCS:.c=.o}}

NAME = minishell

HEADER = ./srcs/head_minishell.h ./libft/srcs/libft.h

LIB			=	./libft/libft.a

LIBS_MAC	=	-L/Users/${USER}/.brew/opt/readline/lib

INCLUDE		=	-I/Users/${USER}/.brew/opt/readline/include -I./srcs/ -I./libft/srcs/

LOGDATE		=	$(shell date)

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

.PHONY: all clean fclean re bonus norm libft readline pull push test

all:		${NAME}

%.o:%.c		${HEADER}
			@${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

libft:		
			@make -C ./libft/

bonus:		${NAME}

${NAME}:	${OBJS} ${HEADER}
			@make -C ./libft/
			@${CC} ${CFLAGC} ${INCLUDE} -o ${NAME} ${OBJS} ${LIB} -lreadline ${LIBS_MAC}
			@echo "${GREEN}${NAME} compile!${SHALLOW}"

test:
			@bash test.sh all

readline:	
			@brew install readline

norm:
			@echo "${GREEN}|-----Chek NORMs!-----|${NEW}"
			@norminette ./srcs/
			@norminette ./libft/srcs/
			@echo "${GREEN}|-----Chek ended!-----|${SHALLOW}"

clean:		
			@${RM} ${OBJS} ${BONUS_OBJS}
			@make clean -C ./libft/
			@echo "${BLUE}clean done!${SHALLOW}"

fclean:		
			@${RM} ${OBJS} ${BONUS_OBJS} ${NAME} ${B_NAME}
			@make fclean -C ./libft/
			@echo "${YELO}fclean done!${SHALLOW}"

pull:		fclean
			@git pull
			@echo "${GREEN}---Pull done!---${SHALLOW}"

push:		fclean
			@git pull
			@git add .
			@git commit -m "${LOGDATE}"
			@git push
			@echo "${GREEN}---Push done!---${SHALLOW}"

re:			fclean all
