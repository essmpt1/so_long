NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC_DIR = .

SRCS = ft_itoa.c ft_strchr.c ft_strjoin.c ft_strlen.c ft_strcpy.c ft_calloc.c \
	ft_bzero.c ft_strncmp.c ft_strchr2.c

OBJS = $(SRCS:%.c=$(SRC_DIR)/%.o)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

all: $(NAME)

#$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
#	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
