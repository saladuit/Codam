/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   width_handler.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jgalloni <jgalloni@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/21 18:35:55 by jgalloni      #+#    #+#                 */
/*   Updated: 2021/02/21 18:36:20 by jgalloni      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"
#include "ftprintf.h"

void	print_width(char c, int len, struct s_format_data *data)
{
	if (len > 0)
		data->return_value += len;
	while (len > 0)
	{
		write(1, &c, 1);
		len--;
	}
}

int	calculate_len(int *width, int *precision, struct s_format_data *data,
char *str)
{
	int	str_len;

	str_len = ft_strlen(str);
	if (str[0] == '-' && data->precision > str_len - 1)
		str_len = ft_strlen(str + 1);
	if (data->precision < str_len)
	{
		*width = data->width - str_len;
		*precision = 0;
	}
	else
	{
		*width = data->width - data->precision;
		if (str[0] == '-')
			*width -= 1;
		*precision = data->precision - str_len;
	}
	if (data->precision == 0 && str[0] == '0')
	{
		*width += 1;
		return (0);
	}
	return (str_len);
}

void	handle_zero_flag(struct s_format_data *data, char *str)
{
	if (data->precision < 0 && data->width > 0)
	{
		data->precision = data->width;
		if (str[0] == '-')
			data->precision -= 1;
	}	
}

void	width_handler(struct s_format_data *data, char *str)
{
	int	width_len;
	int	precision_len;
	int	str_len;

	if (!data->width_negative && data->width_bzero)
		handle_zero_flag(data, str);
	str_len = calculate_len(&width_len, &precision_len, data, str);
	if (!data->width_negative && data->width > 0)
		print_width(' ', width_len, data);
	if (str[0] == '-' && precision_len > 0)
		put_str("-", 1, data);
	if (data->precision > 0)
		print_width('0', precision_len, data);
	if (str[0] == '-' && precision_len > 0)
		put_str(str + 1, str_len, data);
	else
		put_str(str, str_len, data);
	if (data->width_negative)
		print_width(' ', width_len, data);
}
