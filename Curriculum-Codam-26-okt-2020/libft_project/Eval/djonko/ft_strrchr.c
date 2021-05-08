/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 16:14:50 by djonker       #+#    #+#                 */
/*   Updated: 2021/03/02 11:46:57 by djonker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;

	p = (char *) 0;
	while (1)
	{
		if (*s == c)
			p = (char *)s;
		if (*s == 0)
			break ;
		s++;
	}
	return (p);
}
