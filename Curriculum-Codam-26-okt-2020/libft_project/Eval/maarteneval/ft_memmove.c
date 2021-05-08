/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/25 14:52:30 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/10/29 14:26:52 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char			*d;
	const unsigned char		*s;

	d = dest;
	s = src;
	if (d == 0 || s == 0)
		return (0);
	if (dest > src)
	{
		while (n > 0)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
	}
	else if (dest < src)
	{
		while (n-- > 0)
			*d++ = *s++;
	}
	return (dest);
}
