NAME = ft_printf.a

SRCS = ft_printf.c printf_utils_two.c printf_utils.c

CC = cc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		@$(AR) $(NAME) $(OBJS)

clean:
		@$(RM) $(OBJS)

fclean: clean
		@$(RM) $(NAME)

re: fclean all
