/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-waa <svan-waa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/18 15:52:52 by svan-waa      #+#    #+#                 */
/*   Updated: 2021/03/18 14:14:52 by saladin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

#include <stdio.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	temp_to_line(char *temp, char **line)
{
	int	i;

	i = 0;
	line[0] = malloc(ft_strlen(temp) + 1);
	while (temp[i])
	{
		line[0][i] = temp[i];
		i++;
	}
	line[0][i] = '\0';
}
