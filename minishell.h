# ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define BUF 1024 

typedef struct	s_cmd
{
	char		*buf;
	char		**input;
	int			redir_l;
	int			redir_r;
	int			redir_rr;
	int			pipe;
}				t_cmd;

typedef struct	s_struct
{
	t_cmd		*cmd;
}				t_struct;

/*
** utils
*/
int		get_next_line(int fd, char **line);

/*
** sulee
*/
void	ft_parse(t_struct *s, char **input);

/*
** libft
*/
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);

/*
** main
*/
int main(int argc, char **argv, char **envp);

# endif