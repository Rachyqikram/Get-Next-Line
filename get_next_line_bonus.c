/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irachyq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:34:30 by irachyq           #+#    #+#             */
/*   Updated: 2022/04/15 22:57:48 by irachyq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(char *str, int fd)
{
	char	*buffer;
	int		num_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	num_read = 1;
	while (ft_strchr(str, '\n') == NULL && num_read != 0)
	{
		num_read = read(fd, buffer, BUFFER_SIZE);
		if (num_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[num_read] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*change_the_static(char *str)
{
	char	*news;
	size_t	i;
	size_t	l;

	l = 0;
	while (str[l] != '\n' && str[l] != '\0')
		l++;
	if (ft_strlen(str) == l)
	{
		free(str);
		return (NULL);
	}
	news = (char *)malloc((ft_strlen(str) - l + 1) * sizeof(char));
	if (news == NULL)
		return (NULL);
	i = 0;
	while (str[l++])
	{
		news[i] = str[l];
		i++;
	}
	news[i] = '\0';
	free(str);
	return (news);
}

char	*get_line(char *res)
{
	char	*line;
	size_t	l;
	size_t	i;

	l = 0;
	if (res[0] == '\0')
		return (NULL);
	while (res[l] != '\n' && res[l] != '\0')
		l++;
	if (res[l] == '\n')
		l++;
	line = (char *)malloc(sizeof(char) * (l + 1));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (i < l)
	{
		line[i] = res[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*s[10240];
	char		*buf;

	if (fd < 0 || fd >= 10240 || BUFFER_SIZE <= 0)
		return (NULL);
	s[fd] = ft_read(s[fd], fd);
	if (s[fd] == NULL)
		return (NULL);
	buf = get_line(s[fd]);
	s[fd] = change_the_static(s[fd]);
	return (buf);
}
