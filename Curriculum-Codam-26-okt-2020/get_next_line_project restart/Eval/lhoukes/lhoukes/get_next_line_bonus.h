/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 08:08:00 by lhoukes       #+#    #+#                 */
/*   Updated: 2021/02/27 16:38:06 by lisannehouk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

int			get_next_line(int fd, char **line);
int			compair_and_copy(char *line1, char *line2, char to_find);
int			check_read(char *buff_line, int fd);
int			check_line_length(char *line, char to_find);
int			move_and_join(char **line, char *buff_line);
char		*create_line(char *line1, char *line2);

#endif
