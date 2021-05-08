/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_parse_flags.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 14:32:22 by tel-bara      #+#    #+#                 */
/*   Updated: 2020/11/30 21:05:19 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		ft_printf_get_precision(const char **s, t_flags *flags,
va_list args)
{
	(*s)++;
	if (**s == '*')
	{
		flags->precision_value = va_arg(args, int);
		if (flags->precision_value < 0)
		{
			flags->precision_start = 0;
			return ;
		}
		flags->precision_end = 1;
		return ;
	}
	while (**s == '0')
		(*s)++;
	if (ft_isdigit(**s))
	{
		flags->precision_value = ft_atoi(*s);
		*s += ft_numlen(flags->precision_value) - 1;
	}
	else
	{
		(*s)--;
		flags->precision_value = 0;
	}
	flags->precision_end = 1;
}

static void		ft_printf_get_field_width(const char **s, t_flags *flags,
va_list args)
{
	if (**s == '*')
	{
		flags->field_width = va_arg(args, int);
		if (flags->field_width < 0)
		{
			flags->field_width *= -1;
			flags->dash = 1;
		}
	}
	else
	{
		flags->field_width = ft_atoi(*s);
		*s += ft_numlen(flags->field_width) - 1;
	}
}

static void		ft_printf_parse_flags_basics(const char **s, t_flags *flags)
{
	if (**s == '#')
		flags->hashtag = 1;
	else if (**s == '0')
		flags->zero = 1;
	else if (**s == '-')
		flags->dash = 1;
	else if (**s == ' ')
		flags->space = 1;
	else if (**s == '+')
		flags->plus = 1;
	if (flags->dash || flags->precision_start)
		flags->zero = 0;
	if (flags->plus)
		flags->space = 0;
}

static void		ft_printf_parse_length_modifier(const char **s, t_flags *flags)
{
	if (**s == 'l' && *(*s + 1) == 'l')
	{
		flags->length_modifier_ll = 1;
		(*s)++;
	}
	else if (**s == 'h' && *(*s + 1) == 'h')
	{
		flags->length_modifier_hh = 1;
		(*s)++;
	}
	else if (**s == 'l')
		flags->length_modifier_l = 1;
	else if (**s == 'h')
		flags->length_modifier_h = 1;
}

void			ft_printf_parse_flags(const char **s, t_flags *flags,
va_list args)
{
	flags->precision_value = 1;
	while (**s == '#' || ft_isdigit(**s) || **s == '-' || **s == '.' ||
	**s == ' ' || **s == '*' || **s == 'l' || **s == 'h' || **s == '+')
	{
		if (flags->precision_start && !flags->precision_end)
			ft_printf_get_precision(s, flags, args);
		else if (**s == '#' || **s == '0' || **s == '-' ||
		**s == ' ' || **s == '+')
			ft_printf_parse_flags_basics(s, flags);
		else if (**s == '.')
		{
			flags->precision_start = 1;
			flags->precision_end = 0;
			(*s)--;
		}
		else if (flags->precision_start == flags->precision_end &&
		(ft_isdigit(**s) || **s == '*'))
			ft_printf_get_field_width(s, flags, args);
		else if (**s == 'l' || **s == 'h')
			ft_printf_parse_length_modifier(s, flags);
		else
			break ;
		(*s)++;
	}
}
