

#ifndef PIPEX_H
# define PIPEX_H

# include <stddef.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_cmd
{
	char			*path;
	char			**args;
	int				fd[2];
	int				status;
	int				fdopen;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_envs
{
	t_cmd			**cmds;
	int				files[2];
	char			*infile;
	char			*outfile;
	char			**envp;
}					t_envs;

char			*pathfinder(char **envp, char *command);
void			pipex(char **av, char **envp);
char			*triple_strjoin(char *s1, char* s2, char *s3);
void			firstCommand(char **envp, char **av, int *pipefd);
void			secondCommand(char **envp, char **av, int *pipefd);


int				ft_strncmp(const char *str1, const char *str2, size_t n);
int		wdc(char const *s, char c);
size_t	word_size(const char *str, int n, char c);
char			**ft_split(const char *str, char c);
size_t			ft_strlen(char const *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);


#endif