CC = cc 
CFLAGS = -Wall -Wextra -Werror
NAME = getnextlein.a
AR = ar rcs
RM = rm -rf

SRC_MDN = get_next_line.c get_next_line_utils.c

SRC_OBJ = ${SRC_MDN:.c=.o}


all:${NAME}

${NAME}:${SRC_OBJ}
	${AR} $@ $^

%.o:%.c get_next_line.h
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${SRC_OBJ}

fclean:clean
	${RM} ${NAME}

re:fclean all

.PHONY: all fclean clean re

