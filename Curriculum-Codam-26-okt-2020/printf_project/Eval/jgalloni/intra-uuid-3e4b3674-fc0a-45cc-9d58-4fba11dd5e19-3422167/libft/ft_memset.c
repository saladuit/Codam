/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jgalloni <jgalloni@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 13:13:42 by jgalloni      #+#    #+#                 */
/*   Updated: 2020/11/04 15:41:13 by jgalloni      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*str;
	unsigned char	c_value;
	int				i;

	str = b;
	c_value = (unsigned char)c;
	i = 0;
	while (i < (int)len)
	{
		str[i] = c_value;
		i++;
	}
	return (b);
}
