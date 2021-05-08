/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/24 14:58:40 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/10/29 10:43:55 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*src;

	src = s;
	if (src == 0)
		return (0);
	while (n > 0)
	{
		*src = c;
		src++;
		n--;
	}
	return (s);
}
