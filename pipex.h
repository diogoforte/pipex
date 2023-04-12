/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:19:56 by dinunes-          #+#    #+#             */
/*   Updated: 2023/04/12 14:22:28 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stddef.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

char			*pathfinder(char **envp, char *command);
void			pipex(char **av, char **envp);
char			*triple_strjoin(char *s1, char *s2, char *s3);
void			firstcommand(char **envp, char **av, int *pipefd);
void			secondcommand(char **envp, char **av, int *pipefd);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
int				wdc(char const *s, char c);
size_t			word_size(const char *str, int n, char c);
char			**ft_split(const char *str, char c);
size_t			ft_strlen(char const *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);

#endif