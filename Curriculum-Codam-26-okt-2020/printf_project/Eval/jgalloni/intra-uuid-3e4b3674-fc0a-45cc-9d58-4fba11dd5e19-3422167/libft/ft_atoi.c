/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jgalloni <jgalloni@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 18:24:21 by jgalloni      #+#    #+#                 */
/*   Updated: 2021/02/14 12:33:35 by jgalloni      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswhitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	multiplier;
	int	nb;

	i = 0;
	multiplier = 1;
	nb = 0;
	while (str[i] != '\0')
	{
		while (ft_iswhitespace(str[i]))
			i++;
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				multiplier = -1;
			i++;
		}
		while (ft_isdigit(str[i]))
		{
			nb = nb * 10 + str[i] - 48;
			i++;
		}
		return (nb * multiplier);
	}
	return (0);
}
