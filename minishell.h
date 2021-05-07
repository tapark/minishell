# ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_cmd
{
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
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(char *s);
int		ft_strlen(char *s);
int		get_next_line(int fd, char **line);

/*
** sulee
*/
void	ft_parse(char **input);

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