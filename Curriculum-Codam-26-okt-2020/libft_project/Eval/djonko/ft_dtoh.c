/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dtoh.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 02:22:34 by djonker       #+#    #+#                 */
/*   Updated: 2021/02/13 22:36:55 by djonker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dtoh(char c)
{
	int	r;
	int	t;

	t = ft_tolower(c);
	r = t - 87;
	return (r);
}
