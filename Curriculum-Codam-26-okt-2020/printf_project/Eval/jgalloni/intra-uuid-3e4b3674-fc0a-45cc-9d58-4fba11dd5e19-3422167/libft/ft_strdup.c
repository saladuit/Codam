/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jgalloni <jgalloni@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 21:11:07 by jgalloni      #+#    #+#                 */
/*   Updated: 2020/11/04 15:41:41 by jgalloni      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s1);
	str = malloc(len + 1);
	if (!str)
		return (0);
	ft_memcpy(str, (void*)s1, len + 1);
	return ((char *)str);
}
