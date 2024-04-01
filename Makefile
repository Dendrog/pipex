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

$(LIB):
	@make re -C ./libft
 
$(NAME): $(OBJS) $(HEADR)
	$(CC) -o $(NAME) $(OBJS) $(LIB)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	@make clean -C ./libft
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB)

re: fclean all

.PHONY: all clean fclean re
