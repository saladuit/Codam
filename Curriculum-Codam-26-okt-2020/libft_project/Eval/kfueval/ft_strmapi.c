/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 13:20:58 by kfu           #+#    #+#                 */
/*   Updated: 2020/11/09 18:31:53 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*tmp;
	int		slen;
	int		i;

	i = 0;
	if (s == NULL)
		return (0);
	slen = ft_strlen(s) + 1;
	tmp = malloc(sizeof(char) * slen);
	if (tmp == NULL)
	{
		free(tmp);
		return (0);
	}
	while (s[i])
	{
		tmp[i] = f(i, s[i]);
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
