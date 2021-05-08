/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_convert_double_g.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/25 19:26:56 by tel-bara      #+#    #+#                 */
/*   Updated: 2020/12/05 21:38:43 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_printf_trailing_zeroes(t_double *num, t_flags *flags)
{
	num->trailing_zeroes = 0;
	if (!num->decimal)
		num->trailing_zeroes = flags->precision_value - num->intlen;
	while (num->decimal && num->decimal % 10 == 0)
	{
		if (num->decimal)
			num->decimal /= 10;
		num->trailing_zeroes++;
	}
}

static void	ft_printf_get_numlen_double_g(t_double *num, t_flags *flags)
{
	num->intlen = (num->round < 0) ? ft_unumlen(-num->round)
									: ft_numlen(num->round);
	num->intlen = (!num->round) && (num->nbr) ? 0 : num->intlen;
	num->front_zeroes = (num->exp < -1 && num->conv == 'f') ? -num->exp - 1 : 0;
	num->decimal = (ft_exp(10, num->front_zeroes + flags->precision_value
						- num->intlen) * (num->nbr - (double)num->round));
	num->decimal = (num->decimal < 0) ? -num->decimal : num->decimal;
	ft_printf_trailing_zeroes(num, flags);
	num->declen = (num->conv == 'e') ?
	flags->precision_value - num->trailing_zeroes - 1
		: -(num->exp + 1) + flags->precision_value - num->trailing_zeroes;
	num->len = (num->conv == 'e') ? 6 + num->declen :
								1 + num->declen + num->intlen;
	if (flags->hashtag)
		num->len += num->trailing_zeroes;
	if (num->sign || flags->space || flags->plus)
		num->len++;
	if (!flags->hashtag && num->declen <= 0)
		num->len--;
}

static void	ft_printf_put_double_g_as_f(t_double *num, t_flags *flags)
{
	(num->round < 0) ? ft_putunbr_fd(-num->round, 1)
						: ft_putnbr_fd(num->round, 1);
	if (!flags->hashtag && !num->declen)
		return ;
	ft_putchar_fd('.', 1);
	if (num->intlen == flags->precision_value)
		return ;
	ft_printf_write_front_zeroes(num, flags);
	if (num->decimal)
		ft_putnbr_fd(num->decimal, 1);
	while (flags->hashtag && num->trailing_zeroes)
	{
		ft_putchar_fd('0', 1);
		num->trailing_zeroes--;
	}
}

static void	ft_printf_put_double_g_as_e(t_double *num, t_flags *flags)
{
	(num->round < 0) ? ft_putunbr_fd(-num->round, 1) :
						ft_putnbr_fd(num->round, 1);
	if (flags->hashtag || num->decimal)
		ft_putchar_fd('.', 1);
	if (flags->precision_value > 1 && (flags->hashtag || num->decimal))
	{
		ft_printf_write_front_zeroes(num, flags);
		if ((num->decimal || flags->hashtag) && flags->precision_value != 1)
			ft_putnbr_fd(num->decimal, 1);
	}
	(num->exp < 0) ? ft_putstr_fd("e-", 1) : ft_putstr_fd("e+", 1);
	if (-10 < num->exp && num->exp < 10)
		ft_putchar_fd('0', 1);
	(num->exp < 0) ? ft_putnbr_fd(-num->exp, 1) : ft_putnbr_fd(num->exp, 1);
	while (flags->hashtag && num->trailing_zeroes)
	{
		ft_putchar_fd('0', 1);
		num->trailing_zeroes--;
	}
}

void		ft_printf_convert_double_g(t_flags *flags, va_list args, int *count)
{
	t_double	num;

	num.nbr = (double)va_arg(args, double);
	num.sign = 1 / num.nbr < 0 ? '-' : 0;
	if (!flags->precision_start)
		flags->precision_value = 6;
	if (!flags->precision_value)
		flags->precision_value = 1;
	num.conv = 'g';
	ft_printf_get_exp(&num, flags);
	num.conv = (num.exp < -4 || num.exp >= flags->precision_value) ?
					'e' : 'f';
	num.nbr = (num.conv == 'e') ? num.nbr : ft_printf_to_exp(num.nbr, num.exp);
	num.round = (long long)num.nbr;
	ft_printf_get_numlen_double_g(&num, flags);
	ft_printf_double_efg_left_padding(&num, flags, count);
	(num.conv == 'e') ? ft_printf_put_double_g_as_e(&num, flags)
						: ft_printf_put_double_g_as_f(&num, flags);
	ft_printf_double_efg_right_padding(&num, flags, count);
	*count += num.len;
}
