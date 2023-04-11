/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:39:02 by dinunes-          #+#    #+#             */
/*   Updated: 2023/04/11 18:46:17 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *pathfinder(char **envp, char *command)
{
	int i;
	char **paths;
	char *str;
	
	i = 0;
	while (ft_strncmp(envp[i], "PATH", 4))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while(paths[i])
	{
		str = triple_strjoin(paths[i++], "/", command);
		if (access(str, F_OK) == 0)
			break;
		free(str);
	}
	free(paths);
	return(str);
}