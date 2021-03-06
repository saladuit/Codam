/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 15:23:53 by mvan-wij      #+#    #+#                 */
/*   Updated: 2020/10/27 17:31:21 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	return (c >= 'A' && c <= 'Z' ? c - 'A' + 'a' : c);
}
