/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: saladin <saladin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 02:50:56 by saladin       #+#    #+#                 */
/*   Updated: 2021/03/02 09:36:37 by saladin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*p1;
	unsigned const char	*p2;

	p1 = s1;
	p2 = s2;
	if (n == 0)
		return (0);
	while (n)
	{
		if (*p1 == *p2)
		{
			n--;
			p1++;
			p2++;
		}
		else
			return (*p1 - *p2);
	}
	return (0);
}
