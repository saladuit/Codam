/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cstaats <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 12:22:32 by cstaats       #+#    #+#                 */
/*   Updated: 2020/12/09 11:04:48 by candace       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(char const *str)
{
	size_t cnt;

	cnt = 0;
	while (str[cnt] != 0)
	{
		cnt++;
	}
	return (cnt);
}
