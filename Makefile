SRCS =	./main.c \
		./utils/ft_putstr_fd.c \
		./utils/ft_strdup.c \
		./utils/ft_strndup.c \
		./utils/ft_strlen.c \
		./utils/get_next_line.c \
		./utils/ft_env_list.c \
		./utils/ft_strcmp.c \
		./set_env/copy_env_to_list.c \
		./set_env/print_env_list.c \
		./set_env/get_env_token.c \
		./set_env/print_sort_env_list.c \
		./set_env/export_env_list.c \

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

#git_testt
