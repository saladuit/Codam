/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_convert_char.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 15:47:04 by tel-bara      #+#    #+#                 */
/*   Updated: 2020/12/04 14:58:20 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_printf_char_left_padding(t_flags *flags, int *count)
{
	int			left_padding;
	char		padding_char;

	left_padding = (!flags->dash) ? flags->field_width : 0;
	padding_char = (flags->zero) ? '0' : ' ';
	while (left_padding > 1)
	{
		ft_putchar_fd(padding_char, 1);
		(*count)++;
		left_padding--;
	}
}

static void	ft_printf_char_right_padding(t_flags *flags, int *count)
{
	int			right_padding;

	right_padding = (flags->dash) ? flags->field_width : 0;
	while (right_padding > 1)
	{
		ft_putchar_fd(' ', 1);
		(*count)++;
		right_padding--;
	}
}

void		ft_printf_convert_char(t_flags *flags, va_list args, int *count)
{
	unsigned char c;

	c = (unsigned char)va_arg(args, int);
	(*count)++;
	ft_printf_char_left_padding(flags, count);
	if (ft_putlchar_fd(c, 1) == -1)
		*count = -1;
	ft_printf_char_right_padding(flags, count);
}
