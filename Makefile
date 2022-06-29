NAME = push_swap

GCC = cc

SRC = push_swap.c arguments_checker.c push_swap_utils.c push_swap_instructions.c push_swap_actions.c push_swap_checkers.c

all : $(NAME)

$(NAME): $(SRC)
	@gcc $(SRC) -Wall -Werror -Wextra -g -fsanitize=address -o $(NAME)
	@echo "\033[1;32m Push_Swap is ready !"

clean :
		@rm -f $(NAME)
		@echo "\033[1;32m File cleaned !"

fclean : 
		@rm -f $(NAME)
		@echo "\033[1;32m File cleaned !"

re : fclean all

push :
	rm -f $(NAME)
	rm -rf .DS_Store push_swap.dSYM
	git add .
	git status
	git commit -m "Push_swap"
	git push