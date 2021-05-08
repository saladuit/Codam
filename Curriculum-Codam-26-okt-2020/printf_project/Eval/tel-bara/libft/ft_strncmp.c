/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 19:03:13 by tel-bara      #+#    #+#                 */
/*   Updated: 2020/10/31 15:56:31 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		diff;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] && s2[i]) && i < n - 1)
	{
		diff = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (diff)
			return (diff);
		i++;
	}
	diff = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (diff);
}
