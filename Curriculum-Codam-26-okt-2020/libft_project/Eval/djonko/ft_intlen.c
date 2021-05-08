/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 02:04:46 by djonker       #+#    #+#                 */
/*   Updated: 2021/02/13 22:39:27 by djonker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int n)
{
	int	l;

	l = 0;
	if (n <= 0)
		l++;
	while (n != 0)
	{
		n = n / 10 + (l * 0);
		l++;
	}
	return (l);
}