NAME = 		pipex

SRCS =	main.c

LIB = libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(SRCS) $(LIB)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
