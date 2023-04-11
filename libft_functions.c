/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:34:22 by dinunes-          #+#    #+#             */
/*   Updated: 2023/04/06 14:36:58 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (n--)
	{
		if (str1[i] == str2[i] && str1[i] && str2[i])
			i++;
		else
			return (((unsigned char *) str1)[i] - ((unsigned char *) str2)[i]);
	}
	return (0);
}

static int	wdc(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	return (i);
}

static size_t	word_size(const char *str, int n, char c)
{
	size_t	i;

	i = 0;
	while (str[++n] && str[n] != c)
		i ++;
	return (i);
}

char	**ft_split(const char *str, char c)
{
	char	**ret;
	int		size;
	int		j;
	int		i;

	i = 0;
	j = -1;
	size = wdc(str, c);
	ret = (char **)malloc(sizeof(char *) * (size + 1));
	if (!ret)
		return (NULL);
	ret[size] = NULL;
	while (++j < size)
	{
		while (str[i] && str[i] == c)
			i ++;
		if (str[i] && str[i] != c)
			ret[j] = ft_substr(str, i, word_size(str, i - 1, c));
		while (str[i] && str[i] != c)
			i ++;
	}
	return (ret);
}

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
