CC			= gcc -g
CFLAGS		= -Werror -Wall -Wextra #-fsanitize=address
NAME		= so_long

SRC_PATH 	= src/
OBJ_PATH 	= obj/

SRC			= main.c \
			  check_errors.c \
			  extract_map.c \
			  graphic.c \
			  linked_list_utils.c \
			  get_next_line_bonus.c \
			  get_next_line_utils_bonus.c \
			  map_parsing.c \
			  map_parsing_check.c \
			  utils.c \
			  check_paths.c \
			  check_paths_bt.c \
			  moves.c \
			  

MLXLIB			=		./mlx/libmlx.a
LIBFT_MLX		=		$(MAKE) -C mlx
MINILBX			=		-Lmlx -lmlx -framework OpenGL -framework AppKit

ifeq ($(shell uname), Linux)
MLXLIB			=		./mlx-linux/libmlx.a
LIBFT_MLX		=		$(MAKE) -C mlx-linux
MINILBX			=		-L ./mlx-linux/ -lmlx -Ilmlx -lXext -lX11
endif

SRCS			=		$(addprefix $(SRC_PATH), $(SRC))
OBJ				= 		$(SRC:.c=.o)
OBJS			=		$(addprefix $(OBJ_PATH), $(OBJ))
INCS			=		-I ../includes/so_long.h 

all: start $(OBJ_PATH) $(NAME) 

start :
	$(LIBFT_MLX)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c  $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MINILBX) -o $(NAME) 

clean:
	rm -rf $(OBJ_PATH)
	cd mlx && make clean

fclean: clean
	rm -f $(NAME)
	cd mlx && make clean

re: fclean all

.PHONY: all clean fclean re 