NAME = minishell

LIBFT = ./libft/libft.a
LIBDIR = ./libft/

SRCS =	./main.c \
		./get_next_line.c \
		./parser/ft_parse.c \

OBJS = $(SRCS:.c=.o)

INCS = .
RM = rm -f
MAKE = make
CC = gcc
CFLAGS = #-Wall -Wextra -Werror
TO_LIBFT = -C ./libft

$(NAME) : $(OBJS) $(OBJS_CM)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ./libft.a -I $(INCS)

all : $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBDIR)

clean :
		$(RM) $(OBJS)
		$(MAKE) -C $(LIBDIR) clean

fclean : clean
		$(RM) $(NAME)
		$(MAKE) -C $(LIBDIR) fclean

re : fclean all

test :
		./$(NAME)

retest : re test