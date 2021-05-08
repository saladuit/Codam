/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_frearr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: djonker <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/11 21:54:13 by djonker       #+#    #+#                 */
/*   Updated: 2021/02/01 01:46:19 by djonker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_frearr(char **s)
{
	int		n;

	n = 1;
	while (s[n] != NULL)
		n++;
	while (n > 0)
	{
		n--;
		free(s[n]);
	}
	free(s);
	return (NULL);
}
