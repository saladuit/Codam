/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 10:33:54 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/10/29 10:50:27 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;

	d_len = 0;
	s_len = 0;
	i = 0;
	while (dst != 0 && d_len < size && dst[d_len] != 0)
		d_len++;
	while (src != 0 && src[s_len] != 0)
		s_len++;
	if (dst == 0 || src == 0 || d_len == size)
		return (size + s_len);
	while (i < (size - d_len - 1) && src[i] != 0)
	{
		dst[i + d_len] = src[i];
		i++;
	}
	dst[i + d_len] = 0;
	return (d_len + s_len);
}
