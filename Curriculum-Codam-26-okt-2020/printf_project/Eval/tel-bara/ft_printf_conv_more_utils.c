/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_conv_more_utils.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/26 16:21:48 by tel-bara      #+#    #+#                 */
/*   Updated: 2020/12/05 21:41:30 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_printf_write_double_sign(t_double *num, t_flags *flags)
{
	if (num->sign)
		ft_putchar_fd('-', 1);
	else if (flags->plus)
		ft_putchar_fd('+', 1);
	else if (flags->space)
		ft_putchar_fd(' ', 1);
	return ;
}

void		ft_printf_write_front_zeroes(t_double *num, t_flags *flags)
{
	if (!num->decimal && !flags->hashtag)
		num->front_zeroes = num->trailing_zeroes - 1;
	if (num->front_zeroes)
		while (num->front_zeroes)
		{
			ft_putchar_fd('0', 1);
			num->front_zeroes--;
		}
	else
		while (num->decimal && num->declen > ft_numlen(num->decimal))
		{
			ft_putchar_fd('0', 1);
			num->declen--;
		}
}
