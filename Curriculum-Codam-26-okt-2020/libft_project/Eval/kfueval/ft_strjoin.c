/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 14:09:03 by kfu           #+#    #+#                 */
/*   Updated: 2020/11/15 12:01:57 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*tmp;
	int		i;
	int		j;

	if (!str1 || !str2)
		return (NULL);
	tmp = (char *)malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	i = 0;
	if (!tmp)
		return (NULL);
	while (str1[i])
	{
		tmp[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j])
	{
		tmp[i + j] = str2[j];
		j++;
	}
	tmp[i + j] = '\0';
	return (tmp);
}
