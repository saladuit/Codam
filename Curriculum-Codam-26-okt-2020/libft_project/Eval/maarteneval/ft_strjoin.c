/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 20:23:47 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/10/29 12:35:50 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char		*result_string;
	size_t		l1;

	if (s1 == 0 && s2 == 0)
		return (0);
	else if (s1 == 0)
		return (ft_strdup(s2));
	else if (s2 == 0)
		return (ft_strdup(s1));
	l1 = ft_strlen(s1) + ft_strlen(s2);
	result_string = (char*)malloc(l1 + 1);
	if (result_string == 0)
		return (0);
	ft_memset(result_string, 0, l1 + 1);
	ft_strlcat(result_string, s1, l1 + 1);
	ft_strlcat(result_string, s2, l1 + 1);
	return (result_string);
}
