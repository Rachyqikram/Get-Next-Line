/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irachyq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:34:00 by irachyq           #+#    #+#             */
/*   Updated: 2022/04/15 21:52:06 by irachyq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	char	*str;
	size_t	len;
	size_t	j;

	if (s1 == NULL)
		s1 = (char *)ft_calloc(1, sizeof(char));
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(len + 1 * sizeof(char));
	if (str == NULL)
	{
		free(s1);
		return (NULL);
	}
	len = -1;
	while (s1[++len])
		str[len] = s1[len];
	j = 0;
	while (s2[j])
		str[len++] = s2[j++];
	str[len] = '\0';
	free(s1);
	return (str);
}
