/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 08:08:00 by lhoukes       #+#    #+#                 */
/*   Updated: 2021/02/27 16:43:34 by lisannehouk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <limits.h>

char	*create_line(char *line1, char *line2)
{
	int			length_line1;
	int			length_line2;
	char		*give_back;

	if (line1)
		length_line1 = check_line_length(line1, '\0');
	else
		length_line1 = 0;
	length_line2 = check_line_length(line2, '\n');
	give_back = malloc(sizeof(char) * (length_line1 + length_line2 + 1));
	if (give_back == NULL)
	{
		return (NULL);
	}
	compair_and_copy(give_back, line1, '\0');
	if (line1)
	{
		free(line1);
	}
	return (give_back);
}

int	check_read(char *buff_line, int fd)
{
	int			check;

	check = read(fd, buff_line, BUFFER_SIZE);
	if (check < 0)
		return (-1);
	else if (check == 0)
		return (0);
	buff_line[check] = '\0';
	return (check);
}

int	get_next_line(int fd, char **line)
{
	int			read_line;
	static char	buff_line[OPEN_MAX][BUFFER_SIZE + 1];
	int			check;

	if (fd < 0 || read(fd, buff_line[fd], 0) < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	read_line = 1;
	*line = NULL;
	check = 0;
	while (read_line)
	{
		check = check_line_length(buff_line[fd], '\0');
		if (check == 0)
			read_line = check_read(buff_line[fd], fd);
		if (read_line >= 0)
		{
			*line = create_line(*line, buff_line[fd]);
			check = move_and_join(line, buff_line[fd]);
			if (check == 1)
				return (1);
		}
		else
			return (-1);
	}
	return (0);
}
