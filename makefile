NAME=libftprintf.a

SRC=for_hex.c for_int.c for_str.c ft_printf.c utils.c

OBJ=$(SRC:.c=.o)

all : $(NAME)

$(NAME):$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ):
	gcc -Wall -Werror -Wextra -c $(SRC)

clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
re : fclean all
