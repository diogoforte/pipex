/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:19:39 by dinunes-          #+#    #+#             */
/*   Updated: 2023/04/11 17:42:17 by dinunes-         ###   ########.fr       */
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
	if (pipe(pipefd) == -1)
		return perror("ERROR WITH PIPES");
	pid = fork();
	if (pid < 0)
		return perror("ERROR WITH Fork");
	if (pid == 0)
		firstCommand(envp, argv, pipefd);
	
}

void firstCommand(char **envp, char **argv, int *pipefd)
{
	dup2(pipefd[0], STDIN_FILENO);
	//dup2(fd[1], STDOUT_FILENO);
	execve(pathfinder(envp, argv[2]), ft_split(argv[2], ' '), envp);

}

//void secondCommand()