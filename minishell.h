# ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_env
{
	char		*env;
	struct		s_env *next;
}				t_env;

//환경변수 구조체변수를 전역변수로
t_env *g_env;

//환경변수 리스트 함수1 : utils/ft_env_list.c
t_env	*create_env_list_node(char *value);
void	add_env_list_front(t_env **head, t_env *node);
void	add_env_list_back(t_env **head, t_env *node);
void	add_env_list(t_env **head, t_env *node, int n);
void	del_env_list(t_env **head, int n);

//환경변수 리스트함수2
void copy_env_to_list(char **envp);
void print_env_list(t_env **head);
void print_sort_env_list(t_env **head);
char *get_env_variable(char *env);
char *get_env_value(char *env);
void export_env_list(char *env);

//utils
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(char *s);
char	*ft_strndup(char *s, int n);
int		ft_strlen(char *s);
int		ft_strcmp(char *s1, char *s2);
int		get_next_line(int fd, char **line);

//main
//int main(int argc, char **argv, char **envp);

# endif