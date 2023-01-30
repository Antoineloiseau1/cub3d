/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:50:06 by anloisea          #+#    #+#             */
/*   Updated: 2022/12/08 17:36:42 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*join(const char *buf, const char *save)
{
	int		i;
	char	*join;

	if (!save)
		save = ft_strdup("");
	if (!save || !buf)
		return (NULL);
	join = malloc((ft_strlen(buf) + ft_strlen(save) + 1) * sizeof(*join));
	if (!join)
		return (NULL);
	i = -1;
	while (save[++i])
		join[i] = save[i];
	i = -1;
	while (buf[++i])
		join[ft_strlen(save) + i] = buf[i];
	join[ft_strlen(save) + i] = '\0';
	free((void *)save);
	return (join);
}

char	*ft_clean_save(char *save)
{
	int		i;
	char	*clean;
	int		j;

	i = 0;
	j = -1;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	while (save[i] != '\n' && save[i])
		i++;
	if (save[i] == '\n')
		i++;
	clean = malloc((ft_strlen(save) - i + 1) * sizeof(*clean));
	if (!clean)
		return (NULL);
	while (save[i + ++j])
		clean[j] = save[i + j];
	clean[j] = 0;
	free(save);
	return (clean);
}

char	*ft_get_line(char *save)
{
	int		i;
	char	*line;

	i = 0;
	if (save[i] == '\0')
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(*line));
	if (!line)
	{	
		free(save);
		return (NULL);
	}
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

char	*ft_read_file(int fd, char *save)
{
	int		bytes;
	char	*buf;

	bytes = 1;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(*buf));
	if (!buf)
		return (NULL);
	while (!ft_is_endline(save) && bytes)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		buf[bytes] = '\0';
		save = join(buf, save);
	}
	free(buf);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	save[fd] = ft_read_file(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = ft_get_line(save[fd]);
	save[fd] = ft_clean_save(save[fd]);
	return (line);
}
