/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pompote <pompote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:25:58 by yperonne          #+#    #+#             */
/*   Updated: 2023/02/01 22:41:08 by pompote          ###   ########.fr       */
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

int	main( int argc, char **argv)
{
	t_map	*map;

	map = NULL;
	check_args_errors(argc, argv);
	map = extract_map (&argv[1]);
	map_parsing(&map);
	free_map(&map);
	return (0);
}
