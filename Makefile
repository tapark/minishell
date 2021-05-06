SRCS =	./main.c \
		./ft_putstr_fd.c \
		./ft_strdup.c \
		./ft_strlen.c \
		./get_next_line.c \

NAME = minishell
OBJS = $(SRCS:.c=.o)

INCS = .
RM = rm -f
CC = gcc
CFLAGS = #-Wall -Wextra -Werror

$(NAME) : $(OBJS) $(OBJS_CM)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I $(INCS)

all : $(NAME)

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all

test :
		./$(NAME)

retest : re test