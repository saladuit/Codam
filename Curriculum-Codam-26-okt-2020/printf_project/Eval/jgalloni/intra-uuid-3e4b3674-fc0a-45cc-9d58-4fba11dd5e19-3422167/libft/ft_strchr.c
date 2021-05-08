/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jgalloni <jgalloni@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 16:22:13 by jgalloni      #+#    #+#                 */
/*   Updated: 2020/11/04 15:47:30 by jgalloni      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	*ft_strchr(const char *s, int c)
{
	char	ch;
	int		i;

	i = 0;
	ch = (char)c;
	while (s[i])
	{
		if (s[i] == ch)
			return ((void *)&s[i]);
		i++;
	}
	if (c == 0)
		return ((void *)&s[i]);
	return (0);
}
