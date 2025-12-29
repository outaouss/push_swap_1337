NAME    = push_swap
CC      = cc
FLAGS   = -Wall -Wextra -Werror

SRC     = push.c reverse_rotate.c rotate.c swap.c main.c sort_utils.c finding.c \
          error_utils.c utils.c parsing.c ft_split.c seconde_utils.c sorting_algo.c \
          
OBJ     = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "Push_swap Created!"

%.o: %.c push_swap.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	@echo "Objects Deleted!"

fclean: clean
	rm -f $(NAME)
	@echo "Executable Deleted!"

re: fclean all

.PHONY: clean