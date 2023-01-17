/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:55:36 by yperonne          #+#    #+#             */
/*   Updated: 2023/01/17 16:31:54 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	error(char *str)
{
	ft_putstr(str);
	exit (1);
}

void	check_premap_errors(int argc, char **av)
{
	if (argc != 2)
		error("Error : invalid number of arguments");
	if (ft_rev_strncmp(av[1], ".ber", ft_strlen(av[1])) || !ft_strlen(av[1]))
		error("Error : no '.ber' map found");
}

void	check_postmap_errors(t_map **map)
{
	
}