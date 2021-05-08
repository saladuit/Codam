/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_convert_double_f.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/25 19:26:56 by tel-bara      #+#    #+#                 */
/*   Updated: 2020/12/05 21:47:44 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_printf_get_num_f(t_double *num, t_flags *flags)
{
	int			iszero;

	num->decimal =
	(ft_exp(10, flags->precision_value + 1) * (num->nbr - (double)num->round));
	num->decimal = (num->decimal < 0) ? -num->decimal : num->decimal;
	num->declen = ft_numlen(num->decimal / 10);
	iszero = (num->decimal / 10 == 0) ? 1 : 0;
	num->decimal = (num->decimal + 5) / 10;
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

static void	ft_printf_put_double_f(t_double *num, t_flags *flags)
{
	if (!num->decimal)
		num->declen = 1;
	(num->round < 0) ? ft_putunbr_fd(-num->round, 1)
						: ft_putnbr_fd(num->round, 1);
	if (flags->hashtag || flags->precision_value)
		ft_putchar_fd('.', 1);
	if (!flags->precision_value)
		return ;
	while (num->declen < flags->precision_value)
	{
		ft_putchar_fd('0', 1);
		num->declen++;
	}
	ft_putnbr_fd(num->decimal, 1);
}

void		ft_printf_convert_double_f(t_flags *flags, va_list args, int *count)
{
	t_double	num;

	num.nbr = (double)va_arg(args, double);
	num.sign = 1 / num.nbr < 0 ? '-' : 0;
	num.round = (long long)num.nbr;
	if (!flags->precision_start)
		flags->precision_value = 6;
	ft_printf_get_num_f(&num, flags);
	num.len = (num.sign) ? ft_unumlen(-num.round) + flags->precision_value + 2
						: ft_numlen(num.round) + flags->precision_value + 1;
	if (!num.sign && (flags->space || flags->plus))
		num.len++;
	if (!flags->precision_value && !flags->hashtag)
		num.len--;
	ft_printf_double_efg_left_padding(&num, flags, count);
	ft_printf_put_double_f(&num, flags);
	ft_printf_double_efg_right_padding(&num, flags, count);
	*count += num.len;
}
