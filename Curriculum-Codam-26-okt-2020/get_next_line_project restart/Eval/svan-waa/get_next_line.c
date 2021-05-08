/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-waa <svan-waa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/01 13:19:34 by svan-waa      #+#    #+#                 */
/*   Updated: 2021/03/18 14:11:52 by saladin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

int	buf_check(char *buf)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buf[i] != '\0')
			return (0);
		i++;
	}
	return (1);
}

int	buf_to_temp(char *buf, char *temp, int tempindex)
{
	int	i;

	i = 0;
	while (buf[i] == '\0')
		i++;
	while (buf[i] != '\n' && i < BUFFER_SIZE)
	{
		temp[tempindex] = buf[i];
		buf[i] = '\0';
		i++;
		tempindex++;
	}
	temp[tempindex] = '\0';
	if (buf[i] == '\n')
	{
		buf[i] = '\0';
		return (1);
	}
	return (0);
}

int	cpy_buf_to_line(char *buf, char **line)
{
	char	*temp;
	int		i;
	int		rtrn;

	i = 0;
	temp = malloc((BUFFER_SIZE + ft_strlen(line[0]) + 1) * sizeof(char));
	if (!temp)
		return (-1);
	while (line[0][i])
	{
		temp[i] = line[0][i];
		i++;
	}
	rtrn = buf_to_temp(buf, temp, i);
	temp_to_line(temp, line);
	free(temp);
	return (rtrn);
}

int	get_next_line(int fd, char **line)
{
	static char	buf[BUFFER_SIZE + 1];
	int			newlinefound;
	int			eof;

	if (!fd || fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buf[BUFFER_SIZE] = '\0';
	newlinefound = 0;
	eof = 1;
	*line = "";
	while (!newlinefound && eof)
	{
		if (buf_check(buf))
			eof = read(fd, buf, BUFFER_SIZE);
		if (eof > 0)
			newlinefound = cpy_buf_to_line(buf, line);
		if (newlinefound == -1 || eof == -1)
			return (-1);
	}
	if (eof == 0 && buf_check(buf))
		return (0);
	return (1);
}

int 	main(void)
{
	char *line;
	int fd;
	int i;

	i = 1;
	fd = open("tekst", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		printf("line %d: %s\n", i, line);
		i++;
	}
	printf("line %d: %s\n", i, line);
	return (0);
}