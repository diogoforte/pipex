/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:19:39 by dinunes-          #+#    #+#             */
/*   Updated: 2023/04/12 14:23:04 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	if (ac == 5)
		pipex(av, envp);
	else
	{
		perror("Invalid number of parametres");
		return (1);
	}
	return (0);
}

void	pipex(char **av, char **envp)
{
	int	pid;
	int	pipefd[2];

	if (pipe(pipefd))
		perror("Error initializing the pipe");
	pid = fork();
	if (pid < 0)
		perror("Error initializing the fork");
	if (!pid)
		firstCommand(envp, av, pipefd);
	wait(0);
	pid = fork();
	if (pid < 0)
		perror("Error initializing the fork");
	if (!pid)
		secondCommand(envp, av, pipefd);
	close(pipefd[1]);
	close(pipefd[0]);
	wait(0);
}

void	firstcommand(char **envp, char **av, int *pipefd)
{
	int		infile;
	char	**avsplit;

	close(pipefd[0]);
	infile = open(av[1], O_RDONLY, 0644);
	if (infile < 0)
	{
		perror("Error reading infile");
		exit(2);
	}
	dup2(infile, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	avsplit = ft_split(av[2], ' ');
	execve(pathfinder(envp, avsplit[0]), avsplit, envp);
}

void	secondcommand(char **envp, char **av, int *pipefd)
{
	int		outfile;
	char	**avsplit;

	close(pipefd[1]);
	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile < 0)
	{
		perror("Error initializing outfile");
		exit(1);
	}
	dup2(outfile, STDOUT_FILENO);
	dup2(pipefd[0], STDIN_FILENO);
	avsplit = ft_split(av[3], ' ');
	execve(pathfinder(envp, avsplit[0]), avsplit, envp);
}
