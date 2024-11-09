# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cade-oli <cade-oli@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 11:57:05 by cade-oli          #+#    #+#              #
#    Updated: 2024/11/09 15:01:12 by cade-oli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_tests

CC = cc
INCLUDES = -I./include
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)

LIBFT_PATH ?= $(shell pwd)
LIBFT_LIB   = $(LIBFT_PATH)/libft.a

TEST_SRC = $(wildcard tests/*_test.c) main.c
TEST_OBJ = $(TEST_SRC:.c=.o)

UTILS_SRC = $(wildcard utils/*.c)
UTILS_OBJ = $(UTILS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(TEST_OBJ) $(UTILS_OBJ) $(LIBFT_PATH)
	@$(CC) $(CFLAGS) -o $(NAME) $(TEST_OBJ) $(UTILS_OBJ) $(LIBFT_LIB)
	@$(MAKE) --no-print-directory fclean -C $(LIBFT_PATH)
	@echo "$(CYAN)✅ Successfully built $(NAME)!$(RESET)"

$(LIBFT_LIB):
	@if [ -d "$(LIBFT_PATH)" ]; then \
		echo "$(CYAN)📦 Building libft library at $(LIBFT_PATH)...$(RESET)"; \
		$(MAKE) --no-print-directory -C $(LIBFT_PATH); \
	else \
		echo "$(MAGENTA)Error: LIBFT_PATH $(LIBFT_PATH) does not exist.$(RESET)"; \
		exit 1; \
	fi

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(TEST_OBJ) $(UTILS_OBJ)
	@echo "🧹$(MAGENTA) Test object files cleaned.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "🧹$(MAGENTA) All test files cleaned.$(RESET)"
re:
	@echo "$(CYAN)🔄🚀 Rebuilding Tests...$(RESET)"
	@$(MAKE) --no-print-directory
.PHONY: all clean fclean re

#==============================================================================#
#                                  UTILS                                       #
#==============================================================================#

# Colors
MAGENTA = \033[0;35m
CYAN   = \033[0;36m
RESET  = \033[0m
