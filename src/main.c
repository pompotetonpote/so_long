/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:25:58 by yperonne          #+#    #+#             */
/*   Updated: 2023/01/14 16:49:13 by yperonne         ###   ########.fr       */
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
	if (argc < 2)
		return (0);
	map = extract_map (&argv[1]);
	free_map(&map);
	return (0);
}
