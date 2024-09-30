# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eriviere <eriviere@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/27 12:18:27 by eriviere          #+#    #+#              #
#    Updated: 2024/09/30 12:53:43 by eriviere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = src/main.c src/utils.c src/push.c src/swap.c src/rotate.c src/check_error.c src/sort_small_stack.c
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft 
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDE = src/push_swap.h \
					libft/libft.h libft/ft_printf.h
CC = cc 
CFLAGS = -Wall -Wextra -Werror

END = \033[m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
PURPLE = \033[35m
CIAN = \033[36m


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	@echo "\n $(YELLOW) === Compiling libft... === $(END)\n"
	@make -C $(LIBFT_DIR)

%.o: %.c $(INCLUDE)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "\n$(YELLOW)--- Cleaning object files...$(END) ---\n"
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJS)

fclean: clean
	@echo "\n $(YELLOW)--- Cleaning everything, including the executable...$(END) ---\n"
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)


.PHONY: all clean fclean
