NAME		= so_long

FILES		= main.c error.c  game_exit.c  img_setup.c  \
	init_map.c map_check.c  map_to_win.c player_postion.c \
	key_events.c

SRC_PATH	= src/
OBJ_PATH	= obj/
INC_PATH	= include/
OBJ_DIRS	= obj/
MLX_PATH	= lib/mlx/
LIBFT_PATH	= lib/libft/
LIBFT_INC		= $(LIBFT_PATH)include/

MLX			= $(MLX_PATH)libmlx_Linux.a
LIBFT 		= $(LIBFT_PATH)libft.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
CFLAGS		+= -I $(INC_PATH) -I $(LIBFT_INC) -I $(MLX_PATH) -g
CFLAGS 		+= -g -fsanitize=address

LIB_FLAGS	= -lft -lmlx -lm -lbsd -lXext -lX11

RM			= rm -rf

SRC			= $(addprefix $(SRC_PATH), $(FILES))
OBJ			= $(addprefix $(OBJ_PATH), $(FILES:.c=.o))

COLOR_W			= \e[00m
COLOR_R			= \e[31m
COLOR_G			= \e[32m

all : $(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(MLX):
	@make -C $(MLX_PATH)

$(OBJ_DIRS):
	mkdir -p $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_DIRS) $(OBJ) $(MLX) $(LIBFT)
	$(MAKE) --no-print-directory -C $(LIBFT_PATH)
	$(MAKE) --no-print-directory -C $(MLX_PATH)
	@printf "$(COLOR_G)Making $(NAME)\n$(COLOR_W)"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(LIBFT_PATH) -L $(MLX_PATH) $(LIB_FLAGS)
	@printf "$(COLOR_G)Done\n$(COLOR_W)"

clean :
	@printf "$(COLOR_R)Cleaning $(NAME) objects...\n$(COLOR_W)"
	$(MAKE) --no-print-directory fclean -C $(LIBFT_PATH)
	$(MAKE) --no-print-directory clean -C $(MLX_PATH)
	$(RM) $(OBJ)
	$(RM) $(OBJ_DIRS)
	@printf "$(COLOR_G)Done\n$(COLOR_W)"

fclean : clean
	@printf "$(COLOR_R)Cleaning $(NAME)\n$(COLOR_W)"
	$(RM) $(NAME)
	@printf "$(COLOR_G)Done\n$(COLOR_W)"

re : fclean all

.PHONY: all clean fclean re
