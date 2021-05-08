/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strupp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 05:49:38 by djonker       #+#    #+#                 */
/*   Updated: 2021/04/01 04:05:55 by djonker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strupp(char *s)
{
	char	r[1000];
	int		i;
	char	*rr;

	i = 0;
	while (s[i])
	{
		r[i] = ft_toupper(s[i]);
		i++;
	}
	r[i] = '\0';
	rr = r;
	return (rr);
}
