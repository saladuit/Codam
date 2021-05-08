/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   GNLwritingfiles.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: saladin <saladin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/28 14:48:04 by saladin       #+#    #+#                 */
/*   Updated: 2021/01/28 15:24:01 by saladin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

static	void	ft_bzero(void *s, size_t n);

static	void	*ft_memset(void *s, int c, size_t n)
{
	char *ptr;

	ptr = (char*)s;
	while (n > 0)
	{
		(ptr)[n - 1] = ((char)c);
		n--;
	}
	return (s);
}

static	void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

static	void	*ft_memalloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size);
	return (ptr);
}

static	char	*ft_strnew(size_t size)
{
	char	*str;

	if (size == __SIZE_MAX__)
		return (NULL);
	str = (char *)ft_memalloc(size + 1);
	return (str);
}

int		main(void)
{
	int		fd;
	char	*buffer;
	ssize_t	k;

	k = 1;
	buffer = ft_strnew(BUFFER_SIZE);
	fd = open("lorem_ipsum.txt", O_WRONLY | O_APPEND);
	if (fd > -1)
		write(fd, "okrrrr", 7);
	printf("this is number fd: %d\n", fd);
	close (fd);
	return (0);
}