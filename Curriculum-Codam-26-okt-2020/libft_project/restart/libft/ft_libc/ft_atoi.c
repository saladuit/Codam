/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: saladin <saladin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 18:50:33 by saladin       #+#    #+#                 */
/*   Updated: 2021/03/03 10:30:12 by saladin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	bool	ft_checkspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

static	long	long	ft_atoi_limit(long long total, int sign)
{
	if (total < -2147483648 || total > 2147483647)
	{
		if (sign < 0)
			return (0);
		else
			return (-1);
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	long long int	nbr;
	int				sign;

	nbr = 0;
	sign = 1;
	while (ft_checkspace(*nptr))
		nptr++;
	if (*nptr == '-')
	{
		sign = -sign;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr && ft_isdigit(*nptr))
	{
		if (!ft_atoi_limit(nbr * sign, sign))
			return (ft_atoi_limit(nbr * sign, sign));
		nbr = nbr * 10 + *nptr - '0';
		nptr++;
	}
	return ((int)nbr * sign);
}
