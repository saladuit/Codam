/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hexlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 17:34:02 by tel-bara      #+#    #+#                 */
/*   Updated: 2020/11/30 15:52:49 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_hexlen(unsigned long long nbr)
{
	int			len;

	len = 0;
	if (!nbr)
		return (1);
	while (nbr)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}
