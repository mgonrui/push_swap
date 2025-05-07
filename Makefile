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

CC = cc
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: libft $(NAME) push_swap.h

$(NAME): $(OFILES)
	@ $(CC) $(CFLAGS) $(OFILES) libft/libft.a -o $(NAME)


libft:
	@ make -C libft/

clean:
	@ rm -f $(OFILES)
	@ make -C libft/ clean

fclean: clean
	@ rm -f $(NAME)
	@ make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re libft
