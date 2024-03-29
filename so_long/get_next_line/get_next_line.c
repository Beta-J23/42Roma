/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:35:37 by alpelliz          #+#    #+#             */
/*   Updated: 2023/04/04 09:51:16 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_copy_string(int fd, char *save)
{
	char				*buf;
	int					byteline;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (0);
	byteline = 1;
	while (!ft_strchr(save, '\n') && byteline != 0)
	{
		byteline = read(fd, buf, BUFFER_SIZE);
		if (byteline == -1)
		{
			free(buf);
			return (0);
		}
		buf[byteline] = '\0';
		save = ft_strjoin2(save, buf);
	}
	free(buf);
	return (save);
}

char	*extract_line(char *save)
{
	int		i;
	char	*line;

	i = 0;
	if (!save[i])
		return (0);
	while (save[i] != '\0' && save [i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (0);
	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_cleanup(char *save)
{
	int		i;
	int		j;
	char	*reserve;

	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (0);
	}
	reserve = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!reserve)
		return (0);
	i++;
	while (save[i])
		reserve[j++] = save[i++];
	reserve[j] = '\0';
	free(save);
	return (reserve);
}

char	*get_next_line(int fd)
{
	static char		*save;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = read_copy_string(fd, save);
	if (!save)
		return (0);
	line = extract_line(save);
	save = ft_cleanup(save);
	return (line);
}
