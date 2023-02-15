/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:25:58 by yperonne          #+#    #+#             */
/*   Updated: 2023/02/15 14:15:00 by yperonne         ###   ########.fr       */
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
int	key_hook(int keycode, t_vars *vars)
{
	printf("key_hook\n");
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(EXIT_SUCCESS);
	}
	else
		printf("Hello from key_hook!\n");
	return (0);
}

int	exit_window(int keycode, t_vars *vars)
{
	(void) keycode;
	(void) vars;
	exit (EXIT_SUCCESS);
}

int	main( int argc, char **argv)
{
	t_map		*map;
	t_params	*params;
	t_vars		*vars;

	vars = malloc(sizeof (t_vars));
	params = init_elems();
	check_args_errors(argc, argv);
	map = extract_map (&argv[1]);
	map_parsing(&map, params);
	print_tab(params->mtab, params);
	window_init(vars, params);
	put_game(vars, params);
	mlx_hook(vars->win, 17, 1L << 0, exit_window, vars);
	mlx_hook(vars->win, 2, 1L << 0, key_hook, vars);
	mlx_loop(vars->mlx);
	free_map(&map);
	return (0);
}
