NAME = libftprintf.a
SRC = print_char.c print_nbr.c print_str.c print_address.c print_unsigned_int.c print_lower_hexa.c print_upper_hexa.c
OBJ = $(SRC:.c=.o)

all:$(NAME)

$(NAME):$(OBJ)
	ar rc $(NAME) $(OBJ)

%.o:%.c printf.h
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJ)

fclean:clean
	rm -f $(NAME)

re:fclean all