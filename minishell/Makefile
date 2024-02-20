# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbordona <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 16:47:41 by lbordona          #+#    #+#              #
#    Updated: 2024/02/19 23:33:26 by lbordona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -g
CFLAGS = -Wall -Wextra -Werror -pthread -fsanitize=address
RM = rm -rf

NAME = minishell

SRCS = srcs/minishell.c

AUX = aux/ft_putchar_fd.c aux/ft_putstr_fd.c

OBJS = $(SRCS:%.c=%.o) $(AUX:%.c=%.o)

all: $(NAME)


$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.SILENT:
