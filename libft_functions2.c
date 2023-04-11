/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:37:19 by dinunes-          #+#    #+#             */
/*   Updated: 2023/04/07 00:40:39 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *triple_strjoin(char *s1, char* s2, char *s3)
{
	char *res;
	int i;

	i = 0;
	if (!s1 || !s2 || !s3)
		return(NULL);
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1);
	while (*s1)
		res[i++] = *s1++;
 	while(*s2)
		res[i++] = *s2++;
	while(*s3)
		res[i++] = *s3++;
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*substring;
	size_t		i;

	i = ft_strlen(s);
	if (!(s))
		return (NULL);
	if (start >= i)
		len = 0;
	else if (len > (i - start))
		len = i - start;
	substring = malloc(len + 1);
	if (!(substring))
		return (NULL);
	substring[len] = '\0';
	i = 0;
	while (i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	return (substring);
}
