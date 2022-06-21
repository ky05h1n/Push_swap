NAME = push_swap

GCC = cc

SRC = push_swap.c arguments_checker.c push_swap_utils.c

all : $(NAME)

$(NAME): $(SRC)
	@gcc $(SRC) -Wall -Werror -Wextra -g -fsanitize=address -o $(NAME)
	@echo "\033[1;32m Push_Swap is ready !"

clean :
		rm -f $(NAME)

fclean : 
		rm -f $(NAME)
re :
	fclean all