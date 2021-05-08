/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_frenarr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/11 21:54:13 by djonker       #+#    #+#                 */
/*   Updated: 2021/02/01 01:47:39 by djonker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_frenarr(char **s, int n)
{
	while (n > 0)
	{
		n--;
		free(s[n]);
	}
	free(s);
	return (NULL);
}
