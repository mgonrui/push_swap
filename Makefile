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
	$(CC) -Wall -Werror -Wextra  -Ilibft -c $< -o $@

all: libft $(NAME)

$(NAME): $(OFILES)
	$(CC) -Wall -Werror -Wextra $(OFILES) -Llibft -lft -o $(NAME)

libft:
	@ make -C libft/
clean:
	@ rm -f $(OFILES)
	@ make clean -C libft/

fclean: clean
	@ rm -f $(NAME)
	@ make fclean -C libft/

re: fclean all

.PHONY: all clean fclean re bonus
