NAME = 		pipex

SRCS =	main.c\
		utils.c\
		utils2.c

LIB = libft/libft.a

HEADR = pipex.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

all: $(LIB) $(NAME)
 
$(NAME): $(OBJS) $(HEADR)
	$(CC) -o $(NAME) $(OBJS) $(LIB)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
