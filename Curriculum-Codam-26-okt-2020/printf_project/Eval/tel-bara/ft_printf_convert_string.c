/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_convert_string.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 16:31:04 by tel-bara      #+#    #+#                 */
/*   Updated: 2020/11/30 14:25:29 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_printf_str_left_padding(int strlen,
t_flags *flags, int *count)
{
	int			left_padding;
	char		padding_char;

	left_padding = (!flags->dash) ? flags->field_width : 0;
	padding_char = (flags->zero) ? '0' : ' ';
	while (left_padding > strlen)
	{
		ft_putchar_fd(padding_char, 1);
		(*count)++;
		left_padding--;
	}
}

static void	ft_printf_str_right_padding(int strlen, t_flags *flags, int *count)
{
	int			right_padding;

	right_padding = (flags->dash) ? flags->field_width : 0;
	while (right_padding > strlen)
	{
		ft_putchar_fd(' ', 1);
		(*count)++;
		right_padding--;
	}
}

void		ft_printf_convert_string(t_flags *flags, va_list args, int *count)
{
	char	*str;
	int		len;

	str = va_arg(args, char *);
	len = (str) ? ft_strlen(str) : 6;
	if (flags->precision_start && flags->precision_value < len)
		len = flags->precision_value;
	*count += len;
	ft_printf_str_left_padding(len, flags, count);
	if (!str && ft_putlnstr_fd("(null)", 1, len) == -1)
		*count = -1;
	else if (ft_putlnstr_fd(str, 1, len) == -1)
		*count = -1;
	ft_printf_str_right_padding(len, flags, count);
}
