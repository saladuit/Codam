/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 12:17:08 by kfu           #+#    #+#                 */
/*   Updated: 2020/11/15 21:21:14 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_free(char **split)
{
	int i;

	i = 0;
	while (split[i])
	{
		if (split[i])
			free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static int		ft_countwords(char const *s, char c)
{
	int i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static char		**mallocwrite(char **ret, const char *s, char a, int maxwords)
{
	int c;
	int c2;
	int	word;

	c = 0;
	word = 0;
	while (word < maxwords)
	{
		c2 = 0;
		while (s[c] == a)
			c++;
		while (s[c + c2] != a)
			c2++;
		ret[word] = ft_substr(s, c, c2);
		if (!ret[word])
			return (ft_free(ret));
		word++;
		while (s[c] != a)
			c++;
	}
	ret[word] = NULL;
	return (ret);
}

char			**ft_split(char const *s, char a)
{
	char	**ret;
	int		maxwords;
	char	*str;

	if (!s)
		return (NULL);
	else if (!(*s))
	{
		ret = malloc(1 * sizeof(char *));
		ret[0] = NULL;
		return (ret);
	}
	str = ft_substr(s, 0, ft_strlen(s));
	maxwords = ft_countwords(s, a);
	ret = malloc((maxwords + 1) * sizeof(char *));
	if (ret == NULL)
		return (NULL);
	if (ft_strchr(s, a) == 0 || !a)
	{
		ret[0] = str;
		ret[1] = NULL;
		return (ret);
	}
	mallocwrite(ret, s, a, maxwords);
	return (ret);
}
