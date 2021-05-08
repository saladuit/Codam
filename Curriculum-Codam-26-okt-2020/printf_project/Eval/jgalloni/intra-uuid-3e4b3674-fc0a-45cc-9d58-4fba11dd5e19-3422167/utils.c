/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jgalloni <jgalloni@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/21 18:37:35 by jgalloni      #+#    #+#                 */
/*   Updated: 2021/02/21 18:37:36 by jgalloni      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include "ftprintf.h"

void	string_to_upper(char **str)
{
	int	i;

	i = 0;
	while (str[0][i])
	{
		str[0][i] = ft_toupper(str[0][i]);
		i++;
	}
}

int	int_len(int n)
{
	int	count;

	if (n >= 0)
		count = 1;
	else
	{
		count = 2;
		if (n == -2147483648)
			n++;
		n *= -1;
	}
	while (n / 10 > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

void	put_str(char *str, int len, struct s_format_data *data)
{
	int	actual_length;

	actual_length = ft_strlen(str);
	if (len > actual_length || len < 0)
		len = actual_length;
	write (1, str, len);
	data->return_value += len;
}

int	strlen_pointer_address(char *str, struct s_format_data *data)
{
	int	len;

	len = ft_strlen(str);
	if (!data->precision && str[0] == '0' && len == 1)
		len = 0;
	return (len);
}
