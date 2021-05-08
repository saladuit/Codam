/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: candace <candace@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 13:18:47 by candace       #+#    #+#                 */
/*   Updated: 2021/04/06 13:19:10 by candace       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line_bonus.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*cnt;

	cnt = (unsigned char *)s;
	while (n)
	{
		n--;
		*cnt = 0;
		cnt++;
	}
}

static void	ft_joinstr(char *str3, char const *s1, char const *s2)
{
	size_t	cnt;
	size_t	cnt2;
	size_t	cnt3;

	cnt = 0;
	cnt2 = 0;
	cnt3 = 0;
	while (s1[cnt2] != '\0')
	{
		str3[cnt3] = s1[cnt2];
		cnt3++;
		cnt2++;
	}
	while (s2[cnt] != '\0')
	{
		str3[cnt3] = s2[cnt];
		cnt3++;
		cnt++;
	}
	str3[cnt3] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	cnt;
	char	*str3;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	cnt = ft_strlen(s2) + ft_strlen(s1);
	str3 = malloc((cnt + 1) * sizeof(char));
	if (str3 == NULL)
		return (NULL);
	ft_joinstr(str3, s1, s2);
	free ((char *)s1);
	return (str3);
}

char	*ft_strdup(const char *s1)
{
	char	*cpy_s1;
	size_t	cnt;

	cnt = 0;
	cpy_s1 = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (cpy_s1 == NULL)
		return (NULL);
	while (s1[cnt] != '\0')
	{
		cpy_s1[cnt] = s1[cnt];
		cnt++;
	}
	cpy_s1[cnt] = '\0';
	return (cpy_s1);
}
