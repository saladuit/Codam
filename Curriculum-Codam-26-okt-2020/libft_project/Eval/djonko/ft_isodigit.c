/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isodigit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/06 17:19:46 by djonker       #+#    #+#                 */
/*   Updated: 2021/02/13 22:41:35 by djonker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isodigit(int n)
{
	char	*s;

	s = ft_itoa(n);
	while (*s != '\0')
	{
		if (*s >= '0' && *s <= '7')
			s++;
		else
		{
			free(s);
			return (0);
		}
	}
	free(s);
	return (1);
}
