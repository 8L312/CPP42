SRCS		= main.cpp Replacer.cpp

OBJS		= ${SRCS:.cpp=.o}

RM			= rm -f

NAME		= replacer

FLAGS		= -Wall -Wextra -Werror -std=c++98 -pedantic

CC			= g++-11
#CC			= c++

.cpp.o:
			${CC} ${FLAGS} -c $< -o ${<:.cpp=.o}

${NAME}:	${OBJS}
			${CC} ${FLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean cleanR
			${RM} ${NAME}

cleanR:
			${RM} *.replace

re:			fclean all

menage:		
			${RM} *.replace

.PHONY:		all clean fclean re
