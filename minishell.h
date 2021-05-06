# ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

//utils
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(char *s);
int		ft_strlen(char *s);
int		get_next_line(int fd, char **line);

//main
int main(int argc, char **argv, char **envp);

# endif