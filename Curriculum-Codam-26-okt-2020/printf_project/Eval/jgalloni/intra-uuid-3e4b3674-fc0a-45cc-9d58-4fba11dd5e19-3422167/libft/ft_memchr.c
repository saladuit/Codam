/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jgalloni <jgalloni@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 16:22:13 by jgalloni      #+#    #+#                 */
/*   Updated: 2020/11/11 15:07:36 by jgalloni      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int			i;
	const char	*str;

	str = s;
	i = 0;
	while (i < (int)n)
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}
