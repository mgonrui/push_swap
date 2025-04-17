NAME = push_swap
CC = gcc
CFILES =  	main.c \
			basic_llist_actions.c \
			basic_push_swap_actions.c \
			user_input.c \
			commands_push.c \
			commands_swap.c \
			commands_rotate.c \
			commands_reverse_rotate.c \
			stack_utils.c \
			move_stacks.c \
			calculate_costs.c
OFILES = $(CFILES:.c=.o)

%.o : %.c push_swap.h
	$(CC) -Wall -Wextra -Ift_printf -Ilibft -c $< -o $@

all: $(NAME)

$(NAME): $(OFILES)
	$(CC) -Wall -Wextra $(OFILES) -Lft_printf -lft_printf -Llibft -lft -o $(NAME)

clean:
	@ rm -f $(OFILES)

fclean: clean
	@ rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
