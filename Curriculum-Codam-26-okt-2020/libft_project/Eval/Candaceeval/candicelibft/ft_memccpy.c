/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: candace <candace@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 11:47:16 by candace       #+#    #+#                 */
/*   Updated: 2021/01/25 13:38:11 by saladin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t cnt;

	cnt = 0;
	while (cnt < n)
	{
		((char *)dst)[cnt] = (unsigned char)((char *)src)[cnt];
		if (((unsigned char)((char *)src)[cnt]) == (unsigned char)c)
        {
            cnt += 1;
			return (dst + cnt);
        }
		cnt++;
	}
	return (NULL);
}
