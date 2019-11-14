
INCLUDES = -I ./includes

CFLAGS = -Wall -Wextra -Werror $(INCLUDES)

SRCS = ./srcs/ft_swap.c ./srcs/ft_putchar.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c  

OBJS = ${SRCS:.c=.o}

CC = gcc 

all : libft.a

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
clean :
	rm -rf ${OBJS}

re : fclean all

fclean : clean
	rm -rf  ./libft.a


ft_swap.o:
	gcc $(CFLAGS) -c $(SRC)ft_swap.c -c
ft_putchar.o:
	gcc $(CFLAGS) $(SRC)ft_putchar.c -c
ft_putstr.o:
	gcc $(CFLAGS) $(SRC)ft_putstr.c -c
ft_strlen.o:
	gcc $(CFLAGS) $(SRC)ft_strlen.c -c
ft_strcmp.o:
	gcc $(CFLAGS) $(SRC)ft_strcmp.c -c
libft.a: ${OBJS}
	ar rcs ./libft.a ${OBJS}

.PHONY: clean all fclean re
