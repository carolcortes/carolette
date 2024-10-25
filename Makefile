# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cade-oli <cade-oli@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 11:57:05 by cade-oli          #+#    #+#              #
#    Updated: 2024/10/23 15:39:12 by cade-oli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_tests

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I ./include

LIBFT_PATH ?= $(shell pwd)
LIBFT_LIB   = $(LIBFT_PATH)/libft.a

TEST_SRC = $(wildcard tests/*_test.c) main.c
TEST_OBJ = $(TEST_SRC:.c=.o)

all: $(NAME)

$(NAME): $(TEST_OBJ) $(LIBFT_PATH)
	@$(CC) $(CFLAGS) -o $(NAME) $(TEST_OBJ) $(LIBFT_LIB) $(INCLUDES)
	@$(MAKE) fclean -C $(LIBFT_PATH)
	@echo "$(CYAN)✅ Successfully built $(NAME)!$(RESET)"

$(LIBFT_LIB):
	@if [ -d "$(LIBFT_PATH)" ]; then \
		echo "$(CYAN)📦 Building libft library at $(LIBFT_PATH)...$(RESET)"; \
		$(MAKE) -C $(LIBFT_PATH); \
	else \
		echo "$(MAGENTA)Error: LIBFT_PATH $(LIBFT_PATH) does not exist.$(RESET)"; \
		exit 1; \
	fi

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(CYAN)🔧 Compiling $<$(RESET)"

clean:
	@rm -f $(TEST_OBJ)
	@echo "🧹$(MAGENTA) Test object files cleaned.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "🧹$(MAGENTA) All test files cleaned.$(RESET)"
re:
	@echo "$(CYAN)🔄🚀 Rebuilding Tests...$(RESET)"
	@$(MAKE) --no-print-directory fclean all

.PHONY: all clean fclean re

#==============================================================================#
#                                  UTILS                                       #
#==============================================================================#

# Colors
MAGENTA = \033[0;35m
CYAN   = \033[0;36m
RESET  = \033[0m
