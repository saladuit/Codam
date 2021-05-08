/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 02:21:52 by djonker       #+#    #+#                 */
/*   Updated: 2021/03/16 17:05:46 by djonker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	char	**r;
	int		iw;

	if (!s)
		return (NULL);
	iw = 0;
	r = ft_calloc(sizeof(r) * (ft_cntwrd((char *)s, c) + 1), 1);
	if (!r)
		return (NULL);
	while (ft_cntwrd((char *)s, c) > 0)
	{
		while (*s == c)
			s++;
		r[iw] = ft_malstr((char *)s, c);
		if (r[iw] == NULL)
			return (ft_frenarr(r, iw));
		while (*s != c && *s != '\0')
			s++;
		iw++;
	}
	return (r);
}
