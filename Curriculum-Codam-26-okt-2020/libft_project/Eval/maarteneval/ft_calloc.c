/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 14:45:43 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/10/29 10:19:59 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*ft_calloc(size_t nmemb, size_t size)
{
	void			*m;

	if (nmemb == 0 || size == 0)
	{
		size = 1;
		nmemb = 1;
	}
	m = (void*)malloc(nmemb * size);
	if (m == 0)
		return (0);
	ft_bzero(m, size * nmemb);
	return (m);
}
