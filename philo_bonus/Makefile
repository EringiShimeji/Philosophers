NAME := philo_bonus

SRC_DIR := src
OUT_DIR := build
INCLUDE := -Iincludes
CFLAGS := -Wall -Werror -Wextra
DFLAGS := -g -fsanitize=address

SRC := $(shell find $(SRC_DIR) -type f -name '*.c')
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OUT_DIR)/%.o, $(SRC))

all: $(NAME)

debug: CFLAGS += $(DFLAGS)
debug: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(OUT_DIR)/%.o: $(SRC_DIR)/%.c
	-@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
