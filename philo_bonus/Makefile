NAME := philo_bonus

SRC_DIR := src
OUT_DIR := build
INCLUDE := -Iincludes
CFLAGS := -Wall -Werror -Wextra
DFLAGS := -g -fsanitize=address

SRC := src/context/log.c src/context/monitor.c src/context/destroy.c src/context/init.c src/context/read.c src/context/eat.c src/context/think.c src/context/sleep.c src/context/terminate.c src/context/wait.c src/context/write.c src/context/start.c src/utils/ctype/ft_isspace.c src/utils/sem/xopen.c src/utils/sem/read.c src/utils/sem/write.c src/utils/time.c src/utils/stdlib/ft_strtol.c src/utils/stdlib/ft_xmalloc.c src/utils/stdlib/ft_atoi.c src/utils/string/ft_strlen.c src/utils/string/ft_memcmp.c src/utils/string/ft_strjoin.c src/utils/string/ft_memcpy.c src/utils/string/ft_strdup.c src/utils/string/ft_itoa.c src/utils/error/print_error.c src/main.c
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
