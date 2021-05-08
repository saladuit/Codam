/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/30 12:56:35 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/19 11:23:36 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H
# include <vector.h>
# include <alias.h>

typedef struct s_ray
{
	t_vec3		origin;
	t_vec3		dir;
	t_real		min;
	t_real		max;
}	t_ray;

#endif
