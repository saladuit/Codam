/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 14:33:52 by mvan-wij      #+#    #+#                 */
/*   Updated: 2020/10/30 13:24:27 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				offset;
	long long int	result;
	int				is_neg;

	offset = 0;
	while (str[offset] != '\0' && \
		((str[offset] >= '\t' && str[offset] <= '\r') || str[offset] == ' '))
		offset++;
	result = 0;
	is_neg = (str[offset] == '-');
	if (is_neg || str[offset] == '+')
		offset++;
	while (ft_isdigit(str[offset]))
	{
		result *= 10;
		result -= str[offset] - '0';
		offset++;
	}
	return (is_neg ? result : -result);
}
