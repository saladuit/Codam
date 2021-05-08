/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_convert_double_e.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/25 19:26:56 by tel-bara      #+#    #+#                 */
/*   Updated: 2020/12/03 16:43:49 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_printf_get_num_e(t_double *num, t_flags *flags)
{
	int			iszero;

	num->round = (long)num->nbr;
	num->decimal =
	(ft_exp(10, flags->precision_value) * (num->nbr - (double)num->round));
	num->decimal = (num->decimal < 0) ? -num->decimal : num->decimal;
	num->declen = ft_numlen(num->decimal);
	iszero = (!num->decimal) ? 1 : 0;
	if ((ft_numlen(num->decimal) > num->declen
	&& flags->precision_value == num->declen)
	|| (num->decimal && iszero && !flags->precision_value))
	{
		num->round += (num->round < 0) ? -1 : 1;
		num->decimal = 0;
	}
	else
	{
		num->declen = ft_numlen(num->decimal);
	}
}

static void	ft_printf_put_double_e(t_double *num, t_flags *flags)
{
	num->round = (long long)num->nbr;
	(num->round < 0) ? ft_putunbr_fd(-num->round, 1) :
						ft_putnbr_fd(num->round, 1);
	if (flags->hashtag || flags->precision_value)
		ft_putchar_fd('.', 1);
	if (flags->precision_value)
	{
		while (num->declen < flags->precision_value)
		{
			ft_putchar_fd('0', 1);
			num->declen++;
		}
		ft_putnbr_fd(num->decimal, 1);
	}
	(num->exp < 0) ? ft_putstr_fd("e-", 1) : ft_putstr_fd("e+", 1);
	if (-10 < num->exp && num->exp < 10)
		ft_putchar_fd('0', 1);
	(num->exp < 0) ? ft_putnbr_fd(-num->exp, 1) : ft_putnbr_fd(num->exp, 1);
}

void		ft_printf_convert_double_e(t_flags *flags, va_list args, int *count)
{
	t_double	num;

	num.nbr = (double)va_arg(args, double);
	num.sign = 1 / num.nbr < 0 ? '-' : 0;
	if (!flags->precision_start)
		flags->precision_value = 6;
	num.conv = 'e';
	ft_printf_get_exp(&num, flags);
	ft_printf_get_num_e(&num, flags);
	num.len = flags->precision_value + 6;
	if (num.sign || flags->space || flags->plus)
		num.len++;
	if (!flags->precision_value && !flags->hashtag)
		num.len--;
	ft_printf_double_efg_left_padding(&num, flags, count);
	ft_printf_put_double_e(&num, flags);
	ft_printf_double_efg_right_padding(&num, flags, count);
	*count += num.len;
}
