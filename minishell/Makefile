# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbordona <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 16:47:41 by lbordona          #+#    #+#              #
#    Updated: 2024/02/21 11:38:13 by lbordona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -g
CFLAGS = -Wall -Wextra -Werror -pthread -fsanitize=address
RM = rm -rf

NAME = minishell

LIBFT = ./libft/libft.a

PRINTF = ./ft_printf/ft_printf.a

SRCS = srcs/minishell.c srcs/echo.c

#AUX = aux/ft_putchar_fd.c aux/ft_putstr_fd.c aux/ft_calloc.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft

$(PRINTF):
	@$(MAKE) -C ./ft_printf

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

clean:
	@$(MAKE) clean -C ./libft
	@$(MAKE) clean -C ./ft_printf
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(MAKE) fclean -C ./ft_printf
	$(RM) $(NAME)

re: fclean all

.SILENT:
