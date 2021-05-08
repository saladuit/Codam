/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 12:39:22 by mvan-wij      #+#    #+#                 */
/*   Updated: 2020/10/31 14:15:49 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int tmp_n;
	int pow;
	int divided;

	tmp_n = n;
	pow = 1;
	while (tmp_n / 10 != 0)
	{
		tmp_n /= 10;
		pow *= 10;
	}
	if (n < 0)
		ft_putchar_fd('-', fd);
	while (pow != 0)
	{
		divided = n / pow % 10;
		ft_putchar_fd(n < 0 ? '0' - divided : '0' + divided, fd);
		pow /= 10;
	}
}
