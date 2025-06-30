
GREEN = \033[0;32m
RESET = \033[0m

NAME  = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf
MLX_DIR = utils/minilibx-linux
MLX = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
# MLX = -lmlx -lXext -lm
SRC_DIR = src
OBJ_DIR = obj
UTILS_DIR = utils
LIBFT_DIR = $(UTILS_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC =  	cub3d.c \
		validation/validate_imputs.c \
		validation/validate_map.c \
		init/init_app.c \
		init/init_mlx.c \
		game_execution/run_game.c \
		game_execution/listeners.c \
		game_execution/actions.c \
		parse/parse_map.c \
		render/render_map.c \
		error/exit_error.c \
		error/print_error.c \

UTILS_SRC = get_next_line/get_next_line.c \

SRC := $(addprefix $(SRC_DIR)/, $(SRC))
UTILS_SRC := $(addprefix $(UTILS_DIR)/, $(UTILS_SRC))
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
UTILS_OBJ = $(UTILS_SRC:$(UTILS_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(OBJ_DIR) $(NAME)
$(NAME): $(OBJ) $(UTILS_OBJ) 
	@$(MAKE) -C $(LIBFT_DIR)
	        
	@$(CC) $(CFLAGS) $(OBJ) $(UTILS_OBJ) -o $(NAME) $(LIBFT) $(MLX)
	@echo "$(GREEN)Compilation Successful.$(RESET)"
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ 
$(OBJ_DIR)/%.o: $(UTILS_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(RM) $(OBJ) $(OBJ_DIR)
	@echo "$(GREEN)Object files successfully removed.$(RESET)"
fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME) 
	@echo "$(GREEN)Executable file successfully removed.$(RESET)"
re: fclean all
.PHONY: all clean fclean re