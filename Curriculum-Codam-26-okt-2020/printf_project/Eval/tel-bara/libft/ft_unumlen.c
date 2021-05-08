/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_unumlen.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 20:35:16 by tel-bara      #+#    #+#                 */
/*   Updated: 2020/11/30 14:05:22 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_unumlen(unsigned long long nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}
