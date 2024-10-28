NAME_SERVER = server
NAME_CLIENT = client

# Commands
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

# Directories
SRC_DIR = src
OBJ_DIR = obj

# Files
SRCS_SERVER = server.c
SRCS_CLIENT = client.c

SRCS_SERVER := $(addprefix $(SRC_DIR)/, $(SRCS_SERVER))
SRCS_CLIENT := $(addprefix $(SRC_DIR)/, $(SRCS_CLIENT))

OBJS_SERVER = $(SRCS_SERVER:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJS_CLIENT = $(SRCS_CLIENT:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Rules

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) -o $@ $^

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create obj/ directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Rule to clean up object files
clean:
	$(RM) -r $(OBJ_DIR)

# Rule to clean up object files and the executables
fclean: clean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)

# Rule to rebuild everything from scratch
re: fclean all

# Phony targets to avoid conflicts with files of the same name
.PHONY: all clean fclean re