/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putznbr_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 04:22:10 by djonker       #+#    #+#                 */
/*   Updated: 2021/02/13 22:49:09 by djonker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putznbr_fd(int n, int e, int fd)
{
	int	s;

	s = ft_intlen(n) - e;
	while (s != 0)
	{
		ft_putchar_fd('0', fd);
		s++;
	}
	ft_putnbr_fd(n, fd);
}
