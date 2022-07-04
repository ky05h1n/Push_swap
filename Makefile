NAME = push_swap

BNAME = checker

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

BSRC = push_swap_bonus.c \
	   push_swap_bonus_utils_2.c \
	   push_swap_bonus_actions.c \
	   push_swap_bonus_utils.c \
	   push_swap_bonus_read.c \
	   get_next_line.c \
	   get_next_line_utils.c \


all : $(NAME)

$(NAME): $(SRC)
	@gcc $(SRC) -Wall -Werror -Wextra -o $(NAME)
	@echo "\033[1;32m Push_Swap is ready !"

bonus : $(BNAME)

$(BNAME): $(BSRC)
	@gcc $(BSRC) -Wall -Werror -Wextra -o $(BNAME)
	@echo "\033[1;32m Push_Swap_Bonus is ready !"

clean :
		@rm -f $(NAME)
		@rm -f $(BNAME)
		@echo "\033[1;32m File cleaned !"

fclean : 
		@rm -f $(NAME)
		@rm -f $(BNAME)
		@echo "\033[1;32m File cleaned !"

re : fclean all
