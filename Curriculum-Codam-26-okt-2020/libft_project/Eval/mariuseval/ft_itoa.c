/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 15:25:07 by mvan-wij      #+#    #+#                 */
/*   Updated: 2020/10/31 14:18:43 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	int		is_neg;
	char	*res;
	int		i;
	int		tmp_n;

	tmp_n = n;
	is_neg = n < 0;
	i = 0;
	while (tmp_n || i == 0)
	{
		tmp_n /= 10;
		i++;
	}
	res = malloc((i + is_neg + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	res[i + is_neg] = '\0';
	while (i > 0)
	{
		i--;
		res[i + is_neg] = (is_neg ? -(n % 10) : n % 10) + '0';
		n /= 10;
	}
	res[0] = is_neg ? '-' : res[0];
	return (res);
}
