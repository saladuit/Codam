/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_iscntrl_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 15:25:24 by mvan-wij      #+#    #+#                 */
/*   Updated: 2020/10/28 15:27:24 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_iscntrl(int c)
{
	return (!ft_isprint(c));
}
