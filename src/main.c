/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:25:58 by yperonne          #+#    #+#             */
/*   Updated: 2023/02/18 18:13:48 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
/*
création de la map

1. recevoir la map en parametre

2. ouvrir la map file et la lire ligne par ligne,
				 en la renvoyant à chaque fois avec gnl

3. recevoir la ligne et lire lettre par lettre

4. créer la map avec le sprite correspondant avec minilibx   */
int	key_hook(int keycode, t_params *params)
{
	if (keycode == WKEY || keycode == ARROWU)
		upm(params->vars, params);
	if (keycode == AKEY || keycode == ARROWL)
		leftm(params->vars, params);
	if (keycode == DKEY || keycode == ARROWR)
		rightm(params->vars, params);
	if (keycode == SKEY || keycode == ARROWD)
		downm(params->vars, params);
	if (keycode == ESC)
	{
		mlx_destroy_window(params->vars->mlx, params->vars->win);
		exit(EXIT_SUCCESS);
	}
	printf("moves : %d\n", params->moves);
	return (0);
}

int	exit_window(int keycode, t_params *params)
{
	(void) keycode;
	free (params);
	exit (EXIT_SUCCESS);
}

int	main( int argc, char **argv)
{
	t_map		*map;
	t_params	*params;

	params = init_elems();
	check_args_errors(argc, argv);
	map = extract_map (&argv[1]);
	map_parsing(&map, params);
	print_tab(params->mtab, params);
	window_init(params->vars, params);
	put_game(params->vars, params);
	mlx_hook(params->vars->win, 17, 1L << 0, exit_window, params);
	mlx_key_hook(params->vars->win, key_hook, params);
	mlx_loop(params->vars->mlx);
	return (0);
}
