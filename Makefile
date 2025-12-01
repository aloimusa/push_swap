NAME := push_swap
SRC := main.c \
	   operations.c \
	   build_stack.c \
	   depth_sort.c \
	   radix_sort.c

SRC_DIR := src
OBJ_DIR := obj
LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a

OBJ := $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
INC := -I./include -I./libft
CFLAGS := -Wall -Wextra -Werror -O3

.PHONY: all clean fclean re libft

all: $(NAME)

libft:
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	cc $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJ) libft
	cc $(CFLAGS) $(OBJ) -L./$(LIBFT_DIR) -lft -o $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

