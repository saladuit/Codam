/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isws.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: saladin <saladin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/23 11:26:07 by saladin       #+#    #+#                 */
/*   Updated: 2021/02/25 09:44:41 by saladin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isws(int c)
{
	if (c == ' ' || c == '\t' || c == '\f' || c == '\r' || c == '\n'
		|| c == '\v')
		return (1);
	else
		return (0);
}