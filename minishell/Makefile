# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbordona <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 16:47:41 by lbordona          #+#    #+#              #
#    Updated: 2024/02/28 23:57:19 by lbordona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET	= \033[0m
BLACK 	= \033[1;30m
RED 	= \033[1;31m
GREEN 	= \033[1;32m
YELLOW 	= \033[1;33m
BLUE	= \033[1;34m
PURPLE 	= \033[1;35m
CYAN 	= \033[1;36m
WHITE 	= \033[1;37m

CC = cc -g
CFLAGS = -Wall -Wextra -Werror -pthread -fsanitize=address -lreadline
RM = rm -rf

NAME = minishell

LIBFT = ./libft/libft.a

SRCS = srcs/minishell.c srcs/utils.c \
	cmds/echo.c cmds/cd.c cmds/pwd.c \
	aux/epur_str.c cmds/env.c cmds/export.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)


$(LIBFT):
	@$(MAKE) -C ./libft

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	echo " "
	echo "$(PURPLE)Quem tá triste não tá mais!$(RESET)"
	echo " "
	echo "$(GREEN)Minishell executable is ready!$(RESET)"
	echo " "
	

clean:
	@$(MAKE) clean -C ./libft
	@$(RM) $(OBJS)
	echo "$(RED)Object files have been deleted!$(RESET)"

fclean: clean
	@$(MAKE) fclean -C ./libft
	$(RM) $(NAME)
	echo " "
	echo "$(RED)Object and executable files have been deleted!$(RESET)"
	echo " "
	echo "$(PURPLE)All clear sir!$(RESET)"
	echo " "

re: fclean all

.SILENT:
