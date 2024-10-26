#!/bin/sh

make re

# Set LIBFT_PATH to the current directory where the script is run
LIBFT_PATH=$(pwd)

# Navigate to the carolette directory to run the test
cd ~/carolette

# Run make with the dynamically set LIBFT_PATH
make LIBFT_PATH="$LIBFT_PATH" && ./libft_tests

make fclean
