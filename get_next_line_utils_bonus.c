/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irachyq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:34:14 by irachyq           #+#    #+#             */
/*   Updated: 2022/04/15 22:45:36 by irachyq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return (&s[i]);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*res;
	size_t	i;

	res = (char *)malloc(count * size);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		res[i] = 0;
		i++;
	}
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*dest;

	if (s1 == NULL)
		s1 = (char *)ft_calloc(1, sizeof(char));
	i = ft_strlen(s1) + ft_strlen(s2);
	dest = (char *)malloc(i + 1 * sizeof(char));
	if (dest == NULL)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		dest[i++] = s2[j++];
	dest[i] = '\0';
	free(s1);
	return (dest);
}
