/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-waa <svan-waa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/17 13:09:22 by svan-waa      #+#    #+#                 */
/*   Updated: 2021/03/17 12:33:29 by svan-waa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>

size_t	ft_strlen(char *str);
void	temp_to_line(char *temp, char **line);

int		get_next_line(int fd, char **line);

#endif