/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/25 15:37:02 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/10/29 10:45:25 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*mem;
	unsigned char		ch;

	mem = s;
	ch = c;
	if (mem == 0)
		return (0);
	while (n > 0)
	{
		if (*mem == ch)
			return ((void*)mem);
		n--;
		mem++;
	}
	return (0);
}
