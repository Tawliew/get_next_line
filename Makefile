NAME = get_next_line.a 
CC = gcc
CFLAGS = -c -Wall -Werror -Wextra  
RM = rm -f
buff = 1
SRCS =	get_next_line.c \
		get_next_line_utils.c

#.c to .o
OBJ =		${SRCS:%.c=%.o}

all:		${NAME}

${NAME}:	${OBJ}
			ar rcs	${NAME}		${OBJ}

%.o:		%.c
			${CC}	${CFLAGS} -D BUFFER_SIZE=$(buff)	 $< -o $@

test:
	@echo "\n------------------------------------------------------------\n"
	@${CC}	${CCFLAGS}	main.c ${NAME} && ./a.out ronaldo 
	@echo "\n------------------------------------------------------------\n"
clean:
			${RM}	${OBJ}

fclean:		clean
			${RM}	${NAME}

re: fclean all test


.PHONY: all clean fclean re

