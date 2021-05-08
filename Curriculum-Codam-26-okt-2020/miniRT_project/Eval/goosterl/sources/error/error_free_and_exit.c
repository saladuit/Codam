/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_free_and_exit.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 13:26:23 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/15 12:06:49 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <events.h>
#include <minirt.h>
#include <error.h>

t_bool	error_free_and_exit(t_scene *scene, char *message)
{
	if (message)
		error_msg(message);
	free_and_exit(scene);
	return (false);
}
