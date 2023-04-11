/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:19:39 by dinunes-          #+#    #+#             */
/*   Updated: 2023/04/07 01:20:07 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char** envp)
{
	if (argc == 5)
		pipex(argv, envp);
	else
		perror("Invalid number of parametres");
	return (0);
}

int fileOpener(char *argv)
{
	int fd;
	
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (1);
	return (fd);
}

void pipex(char **argv, char **envp)
{
	int fd;
	int pid;
	int pipefd[2];
	
	fd = fileOpener(argv[1]);
	pid = fork();
	//pipe(pipefd);
	if (pid == 0)
	{
		//dup2(fd[1], STDOUT_FILENO);
		execve(pathfinder(envp, argv[2]), ft_split(argv[2], ' '), envp);
	}
	
}

/* void firstCommand()
{
	dup2(fd[1], STDOUT_FILENO);
	execve()
}

void secondCommand() */