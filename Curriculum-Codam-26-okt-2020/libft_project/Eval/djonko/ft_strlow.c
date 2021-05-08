/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlow.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 05:49:38 by djonker       #+#    #+#                 */
/*   Updated: 2021/02/13 23:42:55 by djonker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlow(char *s)
{
	char	r[1000];
	int		i;
	char	*rr;

	i = 0;
	while (s[i])
	{
		r[i] = ft_tolower(s[i]);
		i++;
	}
	r[i] = '\0';
	rr = r;
	ft_putstr_fd(rr, 0);
	return (rr);
}
