/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-bou <nait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:56:47 by nait-bou          #+#    #+#             */
/*   Updated: 2023/12/19 21:55:26 by nait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		return(NULL);
	}
	str = (char *)ft_calloc(ft_strlen(buf) - i + 1, sizeof(char));
	if (!str)
		return(NULL);
	i++;
	while (buf[i])
	{
		str[j] = buf[i];
		i++;
		j++;
	}
	free(buf);
	return(str);
}

static char	*final_r(char *buf)
{
	char	*str;
	int		i;

	i = 0;
	if (!buf[i])
		return(NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	str = (char *)ft_calloc(i + 2, sizeof(char));
	if (!str)
		return(NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		str[i] = buf[i];
		i++;
	}
	if (buf[i] && buf[i] == '\n')
		str[i] = '\n';
	return(str);
}

static char	*joinb(char *s1, char *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	free(s1);
	return(str);
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
	tmp = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (br > 0)
	{
		br = read(fd, tmp, BUFFER_SIZE);
		if (br < 0)
		{
			free(tmp);
			return(NULL);
		}
		buffer = joinb(buffer, tmp);
		if (ft_strchr(tmp, '\n'))
			break;
	}
	free(tmp);
	return(buffer);	
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buf = read_fd(fd, buf);
	if (!buf)
		return(NULL);
	line = final_r(buf);
	buf = keep_b(buf);
	return(line);
}