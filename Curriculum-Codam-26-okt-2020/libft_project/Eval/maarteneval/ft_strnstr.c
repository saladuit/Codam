/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 11:48:46 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/10/29 10:54:30 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (big == 0 || little == 0)
		return (0);
	if (*little == 0)
		return ((char*)big);
	while (i < len && big[i] != 0)
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (j + i < len && little[j] != 0)
			{
				if (big[i + j] != little[j])
					break ;
				j++;
			}
			if (little[j] == 0)
				return ((char*)(big + i));
		}
		i++;
	}
	return (0);
}
