/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:39:02 by dinunes-          #+#    #+#             */
/*   Updated: 2023/04/14 19:20:03 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*pathfinder(char **envp, char *command)
{
	int		i;
	char	**paths;
	char	*str;

	if (!command || !access(command, F_OK))
		return (command);
	i = 0;
	while (ft_strncmp(envp[i], "PATH", 4))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		str = triple_strjoin(paths[i++], "/", command);
		if (!access(str, F_OK))
			break ;
		free(str);
		str = NULL;
	}
	if (!str)
		errorhandling(5);
	free_list(paths);
	return (str);
}

void	free_list(char **list)
{
	int	i;

	if (list)
	{
		i = 0;
		while (list[i])
			free(list[i++]);
		free(list);
	}
}

void	errorhandling(int error)
{
	if (error == 0)
		perror("Invalid number of parametres");
	if (error == 1)
		perror("Error initializing the pipe");
	if (error == 2)
		perror("Error initializing the fork");
	if (error == 3)
		perror("Error reading infile");
	if (error == 4)
		perror("Error initializing outfile");
	if (error == 5)
		perror("No path found");
	if (error == 6)
		perror("Error related to dup2");
	exit(1);
}
