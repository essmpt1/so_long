NAME = so_long
NAME_BONUS = so_long_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -I./minilibx-linux -L./minilibx-linux -lmlx -lX11 -lXext
#MLX_FLAGS = -L./minilibx-linux -I./minilibx-linux -lmlx -lX11 -lXext -lm -lXrandr -lXinerama -lXrender -lbsd -lz

LIBFT_DIR = ./libft
PRINTF_DIR = ./ft_printf
GNL_DIR = ./get_next_line

LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(PRINTF_DIR)/libftprintf.a
FT_GNL = $(GNL_DIR)/libftgetnextline.a

SRC_DIR = .
SRC_BONUS_DIR = ./bonus

SRCS = so_long_draw_game.c so_long_utils.c so_long_validate.c so_long_main.c so_long_clear.c so_long_handle_key.c so_long_init_tex.c \
		so_long_flood.c so_long_camara.c so_long_read_map.c so_long_help.c

SRCS_BONUS = so_long_draw_game_bonus.c so_long_utils_bonus.c so_long_validate_bonus.c so_long_main_bonus.c so_long_clear_bonus.c \
		so_long_help_bonus.c so_long_init_tex_bonus.c so_long_flood_bonus.c so_long_camara_bonus.c so_long_init_tex_2_bonus.c \
		so_long_kill_bonus.c so_long_handle_key_bonus.c so_long_validate_comp_bonus.c so_long_draw_map_bonus.c \
		so_long_kill_2_bonus.c so_long_read_map_bonus.c

OBJS = $(SRCS:%.c=$(SRC_DIR)/%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=$(SRC_BONUS_DIR)/%.o)

$(NAME): $(LIBFT) $(FT_PRINTF) $(FT_GNL) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -L$(GNL_DIR) -lftgetnextline -o $(NAME) $(MLX_FLAGS)

$(NAME_BONUS): $(LIBFT) $(FT_PRINTF) $(FT_GNL) $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -L$(GNL_DIR) -lftgetnextline -o $(NAME_BONUS) $(MLX_FLAGS)


$(LIBFT):
	@make -C $(LIBFT_DIR)

$(FT_PRINTF):
	@make -C $(PRINTF_DIR)

$(FT_GNL):
	@make -C $(GNL_DIR)

bonus: $(NAME_BONUS)

all: $(NAME) $(NAME_BONUS)

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(PRINTF_DIR)
	@make clean -C $(GNL_DIR)

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PRINTF_DIR)
	@make fclean -C $(GNL_DIR)

re: fclean all

.PHONY: bonus all clean fclean re
