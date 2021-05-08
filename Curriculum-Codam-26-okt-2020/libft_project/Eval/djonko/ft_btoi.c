/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_btoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/18 13:44:56 by djonker       #+#    #+#                 */
/*   Updated: 2021/02/13 02:45:04 by djonker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_btoi(int i)
{
	char	*s;
	int		is;
	int		it;
	int		r;

	it = 1;
	is = 0;
	r = 0;
	s = ft_itoa(i);
	while (s[is] != '\0')
	{
		if (s[is] == '1')
			r = r + it;
		it = it * 2;
		is++;
	}
	free(s);
	return (r);
}
