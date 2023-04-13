/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:39:02 by dinunes-          #+#    #+#             */
/*   Updated: 2023/04/12 14:16:24 by dinunes-         ###   ########.fr       */
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
		perror("No path found");
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
