/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:55:36 by yperonne          #+#    #+#             */
/*   Updated: 2023/02/21 18:26:50 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*free content and linkedlist element*/
void	free_map(t_map **map)
{
	t_map	*tmp;

	if (!map || !(*map) || !(*map)->map_line)
	{
		return ;
	}
	while (*map)
	{
		free((*map)->map_line);
		tmp = (*map);
		(*map) = tmp->next;
		free(tmp);
	}
	*map = NULL;
}

void	free_params(t_params *params)
{
	if (!params)
		return ;
	ft_putstr("free_params\n");
	if (!params->mtab->tab)
		return ;
	else
	{
		ft_putstr("free_params22222\n");
		free(params->mtab->tab);
		free(params->mtab);
		free(params);
	}
}

void	error_log(char *str, t_params *params, t_map *map)
{
	(void) params;
	ft_putstr(str);
	free_map(&map);
	ft_putstr("INBETWEEN");
//	free_params(params);
	exit (EXIT_SUCCESS);
}

void	check_args_errors(int argc, char **av)
{
	if (argc != 2)
		error_log("Error : invalid number of arguments", NULL, NULL);
	if (ft_rev_strncmp(av[1], ".ber", ft_strlen(av[1])) || !ft_strlen(av[1]))
		error_log("Error : no '.ber' map found", NULL, NULL);
}
