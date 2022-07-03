NAME = push_swap

GCC = cc

SRC = push_swap.c \
	  push_swap_arguments_checker.c \
	  push_swap_utils.c \
	  push_swap_instructions_1.c \
	  push_swap_actions_0.c \
	  push_swap_actions_1.c \
	  push_swap_actions_2.c \
	  push_swap_actions_3.c \
	  push_swap_instructions_2.c \
	  push_swap_actions_4.c \

all : $(NAME)

$(NAME): $(SRC)
	@gcc $(SRC) -o $(NAME)
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