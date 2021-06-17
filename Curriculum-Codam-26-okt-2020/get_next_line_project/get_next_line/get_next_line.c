/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                 |o_o || |                */
/*                                                     +:+                    */
/*   By: saladin <saladin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/21 09:13:47 by saladin       #+#    #+#                 */
/*   Updated: 2021/06/16 12:34:07 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	newline(int fd, char **line, char **saved)
{
	char *tmp;
	size_t len;

	len = ft_strlen(saved[fd]);
	if (ft_strchr(saved[fd], '\n'))
	{
		tmp = ft_strdup((ft_strchr(saved[fd], '\n') + 1));
		*line = ft_substr(saved[fd], 0, (len - (ft_strlen(tmp) + 1)));
		free(saved[fd]);
		saved[fd] = tmp;
		return (1);
	}
	else
		return (0);
}

int	get_next_line(int fd, char **line)
{
	static char *saved[FOPEN_MAX];
	char buffer[BUFFER_SIZE + 1];
	ssize_t b_read;

	if (saved[fd] == NULL)
		saved[fd] = ft_strdup("");
	b_read = 1;

	if (fd < 0 || !line)
		return (-1);
	while (b_read) {
		if (newline(fd, line, saved))
			return (1);
		b_read = read(fd, buffer, BUFFER_SIZE);
		buffer[b_read] = '\0';
		saved[fd] = ft_strjoin(saved[fd], buffer);
		if (b_read < BUFFER_SIZE && b_read >= 0)
			*line = ft_strdup(saved[fd]);
	}
	return (0);
}
