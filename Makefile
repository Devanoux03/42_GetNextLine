CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = binary

DEPS_DIR	:= deps
SRC_DIR		:= src
OBJ_DIR		:= obj

DEPS		:= \
	get_next_line.h
SRCS		:= \
	learn.c 		\
	get_next_line.c \
	get_next_line_utils.c

SRCS		:= $(SRCS:%=$(SRC_DIR)/%)
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

.PHONY: all
all: $(NAME)
	cd libft && make $@

$(NAME): $(OBJS) $(DEPS_DIR)/$(DEPS)
	$(CC) $(SRCS) $(CFLAGS) -o $@
	

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: debug
debug:
	$(CC) $(SRC)-Wall -Wextra -g

.PHONY: clean
clean: 
	rm -f $(OBJS)
	cd libft && make $@

.PHONY: fclean
fclean: clean
	rm -f $(NAME)
	cd libft && make $@

.PHONY: re
re: fclean all
	cd libft && make $@