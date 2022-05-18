SRCS	= src/Config_parser/ParseConf.cpp \
			src/main.cpp \
			src/Request.cpp \
			src/Response.cpp \
			src/Container.cpp \
			src/ListeningSocket.cpp \
			src/ServSockets.cpp \
			src/CGI.cpp

# SRCS_DIR = src/

# OBJS	=	${addprefix ${SRCS_DIR}, ${SRCS:.cpp=.o}}

OBJS = ${SRCS:.cpp=.o}

NAME = webserv

HEADER = ./src/Config_parser/Server.hpp \
			./src/Response.hpp \
			./src/Request.hpp \
			./src/ListeningSocket.hpp \
			./src/Config_parser/Location.hpp \
			./src/ServSockets.hpp \
			./src/Webserv.hpp \
			./src/CGI.hpp


CXX = c++

RM = rm -f

#CXXFLAGS = -g -std=c++98

CXXFLAGS = -g -std=c++98 -Wall -Wextra -Werror

# COLORS

GREEN	= \033[0;32m
YELO	= \033[0;33m
BLUE	= \033[0;34m
NEW		= \033[0;35m
SHALLOW = \033[0m

# END COLORS

.PHONY: all clean fclean re

%.o: %.cpp
	@${CXX} ${CXXFLAGS}  -c $< -o $@

all:		${NAME}

${NAME}:	${OBJS} ${HEADER}
			@${CXX} ${CXXFLAGC} ${OBJS} -o ${NAME}
			@echo "${GREEN}${NAME} compile!${SHALLOW}"

clean:
			@${RM} ${OBJS}
			@echo "${BLUE}clean done!${SHALLOW}"

fclean:
			@${RM} ${OBJS} ${NAME}
			@echo "${YELO}fclean done!${SHALLOW}"

re:			fclean all
