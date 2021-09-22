SRCS =	main.c initialization.c checker.c utils.c

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = philo
OBJC = ${SRCS:.c=.o}

.c.o:
		${CC} ${FLAGS} -c $<
all: $(NAME)


$(NAME): ${OBJC} Makefile philo.h
		${CC} ${FLAGS} -o ${NAME} ${OBJC}

clean:
		-rm -f ${OBJC}

fclean: clean
		-rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
