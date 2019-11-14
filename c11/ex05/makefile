
CFLAGS = -Wall -Wextra -Werror 

SRCS = ft_atoi.c do_op.c ft_putchar.c  

CC = gcc 

all : do-op

clean :

re : fclean all

fclean : clean
	rm -rf do-op

do-op: ${OBJS}
	gcc $(CFLAGS) $(SRCS) -o do-op

.PHONY: clean all re fclean