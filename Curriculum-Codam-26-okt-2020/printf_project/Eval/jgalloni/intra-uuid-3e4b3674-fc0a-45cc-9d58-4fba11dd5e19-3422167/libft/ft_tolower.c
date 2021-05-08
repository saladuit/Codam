/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tolower.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jgalloni <jgalloni@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 21:19:32 by jgalloni      #+#    #+#                 */
/*   Updated: 2020/11/04 15:35:44 by jgalloni      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
