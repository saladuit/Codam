/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: candace <candace@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/16 11:50:10 by candace       #+#    #+#                 */
/*   Updated: 2021/04/13 14:00:23 by saladin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	cnt;
	char			*substr;

	cnt = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	substr = malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	while (cnt < len && s[cnt + start] != '\0')
	{
		substr[cnt] = s[cnt + start];
		cnt++;
	}
	substr[cnt] = '\0';
	return (substr);
}

size_t	ft_strlen(char const *str)
{
	size_t	cnt;

	cnt = 0;
	while (str[cnt] != 0)
	{
		cnt++;
	}
	return (cnt);
}

char	*ft_linetransfer(char **line, char *leftover)
{
	size_t	extra;
	char	*tplftovr;

	extra = 0;
	while (leftover[extra] != '\n' && leftover[extra] != '\0')
	{
		extra++;
	}
	*line = ft_substr(leftover, 0, extra);
	tplftovr = ft_substr(leftover, extra + 1, ft_strlen(leftover) - extra);
	free(leftover);
	if (*tplftovr == '\0')
		free(tplftovr);
	return (tplftovr);
}

int	ft_isnewline(char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*leftover[FOPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			readreturn;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	readreturn = 1;
	while (readreturn > 0 && ft_isnewline(leftover[fd]) == 0)
	{
		ft_bzero(buf, BUFFER_SIZE + 1);
		readreturn = read(fd, buf, BUFFER_SIZE);
		if (readreturn < 0)
			return (-1);
		if (leftover[fd] == NULL)
			leftover[fd] = ft_strdup(buf);
		else
			leftover[fd] = ft_strjoin(leftover[fd], buf);
	}
	if (leftover[fd] != NULL)
		leftover[fd] = ft_linetransfer(line, leftover[fd]);
	if (readreturn == 0)
		return (0);
	return (1);
}
