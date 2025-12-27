FLAG = -Wall -Werror -Wextra

NAME = push_swap.a

SRC = push.c reverse_rotate.c rotate.c swap.c

OBJ = $(SRC:.c=.o)

all = $(NAME)

$(NAME) = $(OBJ)
	ar rc $(NAME) $(OBJ)
	@echo "Created ! ! "

%.o: %.c push_swap.a
	cc $(FLAG) -c $< -o $@

clean :
	rm -f $(OBJ)
	@echo "Deleted ! ! !"

fclean : clean
	rm -rf $(NAME)
	@echo "Deleted"

.phony : clean