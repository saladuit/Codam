/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: candace <candace@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 10:51:41 by candace       #+#    #+#                 */
/*   Updated: 2020/11/19 13:17:27 by candace       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*cnt;

	cnt = (unsigned char *)b;
	while (len--)
		*cnt++ = (unsigned char)c;
	return (b);
}
