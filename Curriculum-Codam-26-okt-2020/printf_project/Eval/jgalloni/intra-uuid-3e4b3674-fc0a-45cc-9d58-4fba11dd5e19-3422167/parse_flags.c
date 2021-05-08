/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_flags.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jgalloni <jgalloni@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/07 15:21:56 by joellegallu   #+#    #+#                 */
/*   Updated: 2021/02/21 19:27:32 by jgalloni      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ftprintf.h"

int	parse_specifier(char **format, struct s_format_data *data, va_list list)
{
	int	ret;

	if (**format == 'c')
		ret = print_char(list, data, 0);
	else if (**format == 's')
		ret = print_string(data, list);
	else if (**format == 'p')
		ret = print_pointer(list, data);
	else if (**format == 'd' || **format == 'i')
		ret = print_int(data, list, 0);
	else if (**format == 'u')
		ret = print_int(data, list, 1);
	else if (**format == 'x' || **format == 'X')
		ret = print_hexa(list, data, **format);
	else if (**format == '%')
		ret = print_char(list, data, 1);
	else
		return (1);
	*format = *format + 1;
	return (ret);
}

void	parse_star(struct s_format_data *data, va_list list)
{
	int	n;

	n = va_arg(list, int);
	if (n < 0)
	{
		n *= -1;
		data->width_negative = 1;
	}
	data->width = n;
}

void	parse_width(char **format, struct s_format_data *data, va_list list)
{
	int	n;

	while (**format == '0' || **format == '-')
	{
		if (**format == '0')
			data->width_bzero = 1;
		else if (**format == '-')
			data->width_negative = 1;
		*format = *format + 1;
	}
	if (**format == '*')
	{
		parse_star(data, list);
		*format = *format + 1;
	}
	else if (ft_isdigit(**format))
	{
		n = ft_atoi(*format);
		data->width = n;
		*format += int_len(n);
	}
}

void	parse_precision(char **format, struct s_format_data *data, va_list list)
{
	int	n;

	if (**format == '.')
	{
		data->precision = 0;
		*format = *format + 1;
	}
	if (**format == '*')
	{
		n = va_arg(list, int);
		data->precision = n;
		*format = *format + 1;
	}
	else if (ft_isdigit(**format))
	{
		if (**format == '0' && ft_isdigit(*(*format + 1)))
			*format = *format + 1;
		n = ft_atoi(*format);
		data->precision = n;
		*format += int_len(n);
	}
}

int	parse_flags(char **format, struct s_format_data *data, va_list list)
{
	int	ret;

	parse_width(format, data, list);
	parse_precision(format, data, list);
	ret = parse_specifier(format, data, list);
	return (ret);
}
