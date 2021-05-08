/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_conv_utils.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/26 16:21:48 by tel-bara      #+#    #+#                 */
/*   Updated: 2020/12/05 21:41:16 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_printf_get_exp(t_double *num, t_flags *flags)
{
	double	round;

	num->exp = 0;
	if (!num->nbr)
		return ;
	while (num->nbr < -10 || num->nbr > 10)
	{
		num->nbr /= 10;
		num->exp++;
	}
	while (-1 < num->nbr && num->nbr < 1 && num->nbr)
	{
		num->nbr *= 10;
		num->exp--;
	}
	if (num->conv == 'g')
		round = 0.5 / ft_exp(10, flags->precision_value - 1);
	else
		round = 0.5 / ft_exp(10, flags->precision_value);
	num->nbr += (num->nbr < 0) ? -round : round;
	if (num->nbr < -10 || num->nbr > 10)
	{
		num->nbr /= 10;
		num->exp++;
	}
}

double		ft_printf_to_exp(double nbr, int exp)
{
	if (nbr && exp)
	{
		while (exp < 0)
		{
			nbr /= 10;
			exp++;
		}
		while (exp > 0)
		{
			nbr *= 10;
			exp--;
		}
	}
	return (nbr);
}

void		ft_printf_write_sign(long long nbr, t_flags *flags)
{
	if (nbr < 0)
		ft_putchar_fd('-', 1);
	else if (flags->plus)
		ft_putchar_fd('+', 1);
	else if (flags->space)
		ft_putchar_fd(' ', 1);
	return ;
}

void		ft_printf_double_efg_left_padding(t_double *num, t_flags *flags,
int *count)
{
	int			left_padding;
	char		padding_char;
	int			sign;

	left_padding = (!flags->dash) ? flags->field_width : 0;
	padding_char = (flags->zero) ? '0' : ' ';
	sign = (num->sign || flags->space || flags->plus) ? 1 : 0;
	if (sign && flags->zero)
		ft_printf_write_double_sign(num, flags);
	while (left_padding > num->len)
	{
		ft_putchar_fd(padding_char, 1);
		(*count)++;
		left_padding--;
	}
	if (sign && !flags->zero)
		ft_printf_write_double_sign(num, flags);
}

void		ft_printf_double_efg_right_padding(t_double *num, t_flags *flags,
int *count)
{
	int			right_padding;

	right_padding = (flags->dash) ? flags->field_width : 0;
	while (right_padding > num->len)
	{
		ft_putchar_fd(' ', 1);
		(*count)++;
		right_padding--;
	}
}
