# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbordona <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 16:47:41 by lbordona          #+#    #+#              #
#    Updated: 2024/01/24 13:03:34 by lbordona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -g
CFLAGS = -Wall -Wextra -Werror -pthread -fsanitize=address
RM = rm -rf
LIBFT = ./libft/libft.a

NAME = minishell

SRCS = srcs/minishell.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	@$(MAKE) clean -C ./libft
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

.SILENT:
