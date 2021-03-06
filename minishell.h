# ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_env
{
	char		*env;
	struct		s_env *next;
}				t_env;

typedef struct	s_cmd
{
	char		*buf;
	char		**token;
	int			redir;
	int			pipe;
	int			semi;
	struct		s_cmd *prev;
	struct		s_cmd *next;
}				t_cmd;

//환경변수 전역변수
char **g_env;

//환경변수 리스트함수2
char **copy_envp(char **envp);
void print_env_line(void);
void print_sort_env_line(void);
char *get_env_variable(char *env);
char *get_env_value(char *env);
void export_env_line(char *line);
int env_exist_check(char *var);
void unset_env_line(char *line);

//parse
char *get_pure_string(char *buf);
int quote_error_check(char *buf);
int count_token(char *buf);
char **get_token(char *buf);

void	ready_to_parse(t_cmd *cmd, char **input);
void    put_cmd_to_s(t_cmd *cmd, char **input_ps);

//built_in
void get_built_in_cmd(t_cmd *cmd);
int var_valid_check(char *line);
void ft_env(void);
void ft_export(t_cmd *cmd);
void ft_unset(t_cmd *cmd);
void ft_exit(t_cmd *cmd);

//utils
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(char *s);
char	*ft_strndup(char *s, int n);
int		ft_strlen(char *s);
int		ft_strcmp(char *s1, char *s2);
int		get_next_line(int fd, char **line);
char	*ft_strjoin_free2(char *s1, char *s2);
char	*ft_strtrim(char const *s1, char const *set);
void	free_double(char **str);

t_cmd	*create_cmd_list_node(char *buf, int redir, int pipe, int semi);
void	add_cmd_list_back(t_cmd **head, t_cmd *node);



//main
int main(int argc, char **argv, char **envp);

# endif