NAME = libftprintf.a

LIBFT = ./libft/libft.a

SOURCES_PRINTF = 	ft_printf.c \
			ft_print_hex.c \
			ft_print_ptr.c \
			ft_print_str.c \
			ft_print_u.c \


OBJECTS_PRINTF = $(SOURCES_PRINTF:.c=.o)

CC = gcc

GFLAGS = -Wall -Wextra -Werror

HEADER = libft.h

%.o: %.c
	@$(CC) $(GFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS_PRINTF)
	@make -s -C ./libft
	@cp ./libft/libft.a ${NAME}
	@ar rc ${NAME} $(OBJECTS_PRINTF)
	@echo "$(BOLD)[ 🪄 ft_printf compiled! ]$(NC)"

clean:
		@make clean -s -C ./libft
		@rm -f $(OBJECTS_PRINTF)

fclean: clean
		@make fclean -s -C ./libft
		@rm -f ${NAME}

re: fclean all
