NAME        = push_swap
BONUS_NAME  = checker
CC          = cc
FLAGS       = -Wall -Wextra -Werror

COMMON_SRC  = push.c reverse_rotate.c rotate.c swap.c sort_utils.c finding.c \
              error_utils.c utils.c parsing.c ft_split.c seconde_utils.c \

MANDATORY_SRC = main.c sorting_algo.c
BONUS_SRC     = checker.c get_next_line.c get_next_line_utils.c

COMMON_OBJ    = $(COMMON_SRC:.c=.o)
MANDATORY_OBJ = $(MANDATORY_SRC:.c=.o)
BONUS_OBJ     = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(COMMON_OBJ) $(MANDATORY_OBJ)
	@$(CC) $(FLAGS) $(COMMON_OBJ) $(MANDATORY_OBJ) -o $(NAME)
	@echo "\033[0m \033[97mPush_swap Created \033[92m√"

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(COMMON_OBJ) $(BONUS_OBJ)
	@$(CC) $(FLAGS) $(COMMON_OBJ) $(BONUS_OBJ) -o $(BONUS_NAME)
	@echo "\033[0m \033[97mChecker Created \033[92m√"

%.o: %.c push_swap.h
	@echo "\033[0m \033[97mPush_swap Created \033[92m√"
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(COMMON_OBJ) $(MANDATORY_OBJ) $(BONUS_OBJ)
	@echo "\033[0m \033[97mObjects Deleted ! \033[92m√"

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)
	@echo "\033[0m \033[97mExecutables Deleted ! \033[92m√"

re: fclean all

.PHONY: clean