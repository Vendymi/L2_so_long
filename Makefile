NAME = so_long

CC = cc
CFLAGS = -Werror -Wall -Wextra
RM = rm -rf

#includes
INCS	=	-I/user/include \
			ft_printf/libftprintf.a \
			mlx_linux/libmlx_Linux.a


#sources
SRC_PATH	=	src/
SRC			= 	so_long.c \
				graphics_loading.c \
				map_checking.c \
				map_handling.c \
				run_game.c \
				get_next_line.c \
				get_next_line_utils.c

SRCS =	$(addprefix $(SRC_PATH), $(SRC))

#objects
OBJ_PATH	=	obj/
OBJ			=	$(SRC:.c=.o)
OBJS		=	$(addprefix $(OBJ_PATH), $(OBJ))

#compiling
.PHONY: all
all: ft_printf/libftprintf.a mlx_linux/libmlx_Linux.a $(OBJ_PATH) $(NAME)

ft_printf/libftprintf.a:
	@make -s -C ./ft_printf

mlx_linux/libmlx_Linux.a:
	@make -s -C ./mlx_linux

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJS)
	@echo "$(BOLD)[ 🙊 Compiling shit together... ]$(NC)"
	@$(CC) -g $(CFLAGS) $(OBJS) $(INCS) -o $(NAME) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
	@echo "$(BOLD)[ 🪄 Program ready! ]$(NC)"

clean :
	@$(RM) $(OBJS)
	@make clean -s -C ./ft_printf
	@echo "$(BOLD)[ 🙊 Cleaning objects... Done... ]$(NC)"

fclean : clean
	@echo "$(BOLD)[ 🙊 Cleaning... ]$(NC)"
	@$(RM) $(NAME)
	@make fclean -s -C ft_printf
	@echo "$(BOLD)[ 🙊 Done... ]$(NC)"

re : fclean all


