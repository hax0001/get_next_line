/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-bou <nait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:11:51 by nait-bou          #+#    #+#             */
/*   Updated: 2023/12/28 17:46:44 by nait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*keep_b(char *buf)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}
	str = (char *)malloc(ft_strlen(buf) - i++ + 1);
	if (!str)
		return (NULL);
	while (buf[i])
	{
		str[j] = buf[i];
		i++;
		j++;
	}
	str[j] = '\0';
	free(buf);
	return (str);
}

static char	*final_r(char *buf)
{
	char	*str;
	int		i;

	if (!buf[0])
		return (NULL);
	if (!ft_strchr(buf, '\n'))
		return (ft_strdup(buf));
	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	str = (char *)malloc(i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		str[i] = buf[i];
		i++;
	}
	if (buf[i] && buf[i] == '\n')
	{
		str[i] = '\n';
		str[i + 1] = '\0';
	}
	return (str);
}

static char	*joinb(char *s1, char *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	free(s1);
	return (str);
}

static char	*read_fd(int fd, char *buffer)
{
	char	*tmp;
	int		br;

	br = 1;
	if (!buffer)
	{
		buffer = (char *)malloc(1);
		buffer[0] = '\0';
	}
	tmp = (char *)malloc(BUFFER_SIZE + 1);
	while (br > 0)
	{
		br = read(fd, tmp, BUFFER_SIZE);
		if (br == -1)
			return (free(buffer), free(tmp), NULL);
		tmp[br] = '\0';
		buffer = joinb(buffer, tmp);
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	free(tmp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buf[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (free(buf[fd]), buf[fd] = NULL, NULL);
	buf[fd] = read_fd(fd, buf[fd]);
	if (!buf[fd])
		return (NULL);
	line = final_r(buf[fd]);
	buf[fd] = keep_b(buf[fd]);
	return (line);
}
