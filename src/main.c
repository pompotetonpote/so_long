/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pompote <pompote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:25:58 by yperonne          #+#    #+#             */
/*   Updated: 2023/01/14 09:12:34 by pompote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
création de la map

1. recevoir la map en parametre

2. ouvrir la map file et la lire ligne par ligne,
				 en la renvoyant à chaque fois avec gnl

3. recevoir la ligne et lire lettre par lettre

4. créer la map avec le sprite correspondant avec minilibx   */

int	main( int argc, char **argv)
{
	int	map;

	(void)argc;
	(void)argv;
	map = open(argv[1], O_RDONLY);
	close(map);
	return (0);
}
