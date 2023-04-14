/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:19:39 by dinunes-          #+#    #+#             */
/*   Updated: 2023/04/14 19:15:29 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	if (ac == 5)
		pipex(av, envp);
	else
		errorhandling(0);
	return (0);
}

void	pipex(char **av, char **envp)
{
	int	pid;
	int	pipefd[2];

	if (pipe(pipefd))
		errorhandling(1);
	pid = fork();
	if (pid < 0)
		errorhandling(2);
	if (!pid)
		firstcommand(envp, av, pipefd);
	wait(0);
	pid = fork();
	if (pid < 0)
		errorhandling(2);
	if (!pid)
		secondcommand(envp, av, pipefd);
	close(pipefd[1]);
	close(pipefd[0]);
	wait(0);
}

void	firstcommand(char **envp, char **av, int *pipefd)
{
	int		infile;
	char	**avsplit;
	char	*str;

	close(pipefd[0]);
	infile = open(av[1], O_RDONLY);
	if (infile < 0)
		errorhandling(3);
	if (dup2(infile, STDIN_FILENO) < 0)
		errorhandling(6);
	if (dup2(pipefd[1], STDOUT_FILENO) < 0)
		errorhandling(6);
	avsplit = ft_split(av[2], ' ');
	str = pathfinder(envp, avsplit[0]);
	execve(str, avsplit, envp);
	free_list(avsplit);
	free(str);
	exit(4);
}

void	secondcommand(char **envp, char **av, int *pipefd)
{
	int		outfile;
	char	**avsplit;
	char	*str;

	close(pipefd[1]);
	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
		errorhandling(4);
	if (dup2(outfile, STDOUT_FILENO) < 0)
		errorhandling(6);
	if (dup2(pipefd[0], STDIN_FILENO) < 0)
		errorhandling(6);
	avsplit = ft_split(av[3], ' ');
	str = pathfinder(envp, avsplit[0]);
	execve(str, avsplit, envp);
	free_list(avsplit);
	free(str);
	exit(4);
}
