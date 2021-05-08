/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:15:07 by goosterl      #+#    #+#                 */
/*   Updated: 2021/04/15 11:24:12 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <stdlib.h>
#include <error.h>
#include <init.h>
#include <utils.h>
#include <bitmap.h>
#include <libft.h>
#include <parse.h>
#include <events.h>

int	main(int argc, char *argv[])
{
	t_scene		*scene;

	if (argc < 2 || argc > 3)
		print_welcome();
	scene = scene_allocate();
	if (scene == NULL)
		error_exit(ERR_SCENE_ALLOC_FAILED);
	if (ft_match(argv[2], RT_SAVE_SS))
		scene->viewport = shaded;
	else if (argv[2])
		error_free_and_exit(scene, ERR_BAD_ARG);
	if (scene_init(scene, argv[1]) == false)
		error_free_and_exit(scene, ERR_SCENE_INIT_FAILED);
	if (buffer_init(scene) == false)
		error_free_and_exit(scene, ERR_MLX_INIT_FAILED);
	if (update(scene) == false)
		error_free_and_exit(scene, ERR_SCENE_FAILURE);
	if (scene->viewport == shaded)
	{
		console_put(RT_SAVE);
		save_bmp(&scene->main, "Screenshot.bmp");
		free_and_exit(scene);
	}
	hook_init(scene);
	return (1);
}
