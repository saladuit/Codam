/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 15:23:10 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/19 11:17:28 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H
# include <vector.h>
# if IS_BONUS == 1
#  include <color_bonus.h>
# endif

typedef t_vec3	t_rgb;

# if IS_BONUS == 0

typedef struct s_material
{
	t_rgb		diffuse;
}	t_material;

# endif

/*
**	convert 8byte pixel data into t_rgb struct (with values of unit length)
*/
t_rgb			data_to_rgb(const unsigned int color);

/*
**	convert t_rgb struct into 8byte pixel data
*/
unsigned int	rgb_to_data(const t_rgb color);

#endif
