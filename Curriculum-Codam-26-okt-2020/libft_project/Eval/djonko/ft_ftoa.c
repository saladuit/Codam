/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ftoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 03:46:17 by djonker       #+#    #+#                 */
/*   Updated: 2021/02/08 06:30:14 by djonker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ftoa(double n)
{
	char		*ti;
	char		*tf;
	int			i;
	char		*r;

	ti = ft_itoa(n);
	i = ft_ftoi(n);
	r = ft_itoa(i);
	tf = ft_strjoin(".", r);
	free(r);
	r = ft_strjoin(ti, tf);
	free(ti);
	free(tf);
	return (r);
}
