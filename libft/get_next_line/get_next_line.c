/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <cfeliz-r@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:16:31 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/05 15:23:15 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;
	char	*temp;

	buff = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		buff[rd_bytes] = '\0';
		if (left_str)
		{
			temp = ft_strjoin(left_str, buff);
			free(left_str);
			left_str = temp;
		}
		else
			left_str = ft_strdup(buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (left_str);
}

static char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		line = ft_calloc(i + 2, sizeof(char));
	else
		line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

static char	*ft_rest(char *save)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	s = ft_calloc(ft_strlen(save) - i + 1, sizeof(char));
	if (!s)
		return (NULL);
	i++;
	j = 0;
	while (save[i])
		s[j++] = save[i++];
	s[j] = '\0';
	free(save);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*buf[1045];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf[fd] = ft_read(fd, buf[fd]);
	if (!buf[fd])
		return (NULL);
	line = ft_line(buf[fd]);
	buf[fd] = ft_rest(buf[fd]);
	return (line);
}
