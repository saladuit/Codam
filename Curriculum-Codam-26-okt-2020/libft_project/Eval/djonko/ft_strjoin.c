/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 16:17:34 by djonker       #+#    #+#                 */
/*   Updated: 2021/03/30 18:04:29 by djonker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		c1;
	int		c2;
	char	*r;

	c1 = 0;
	c2 = 0;
	if (s1 == NULL)
		return (ft_malstr((char *)s2, '\0'));
	if (s2 == NULL)
		return (ft_malstr((char *)s1, '\0'));
	r = ft_calloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1, 1);
	if (r == 0x0)
		return (r);
	while (c1 < (int)ft_strlen((char *)s1))
	{
		r[c1] = s1[c1];
		c1++;
	}
	while (c2 < (int)ft_strlen((char *)s2))
	{
		r[c1 + c2] = s2[c2];
		c2++;
	}
	r[c1 + c2] = '\0';
	return (r);
}
