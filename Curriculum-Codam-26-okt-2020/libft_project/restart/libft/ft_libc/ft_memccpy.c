/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: saladin <saladin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 02:50:52 by saladin       #+#    #+#                 */
/*   Updated: 2021/03/02 09:36:16 by saladin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned const char	*s;
	unsigned char		*d;

	d = dest;
	s = src;
	while (n)
	{
		*d = *s;
		if (*s == (unsigned char)c)
			return (d + 1);
		d++;
		s++;
		n--;
	}
	return (NULL);
}
