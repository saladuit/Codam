/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: candace <candace@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 13:30:11 by candace       #+#    #+#                 */
/*   Updated: 2021/01/25 14:13:15 by saladin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*csrc;
	char	*cdst;
	size_t	cnt;

	if (src == dst)
		return (dst);
	csrc = (char *)src;
	cdst = (char *)dst;
	if (src < dst)
	{
		cnt = len;
		while (cnt-- > 0)
			cdst[cnt] = csrc[cnt];
	}
	else
	{
		cnt = 0;
		while (cnt < len)
		{
			cdst[cnt] = csrc[cnt];
			cnt++;
		}
	}
	return (dst);
}
