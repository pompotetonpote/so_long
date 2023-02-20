/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pompote <pompote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:55:36 by yperonne          #+#    #+#             */
/*   Updated: 2023/02/20 20:07:26 by pompote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*free content and linkedlist element*/
void	free_map(t_map **map)
{
	t_map	*tmp;

	ft_putstr("coucou");

	printf("AAAAA__%s\n\n", (*map)->map_line);
	if (!map || !(*map) || !(*map)->map_line)
	{
		printf("coucou2");
		return ;
	}
	while (*map)
	{
		printf("Before-------------------%s\n", (*map)->map_line);
		free((*map)->map_line);
		tmp = (*map);
		(*map) = tmp->next;
		free(tmp);
	}
	*map = NULL;
}

void	free_params(t_params *params)
{
	if (params->mtab->tab)
	{
		free(params->mtab->tab);
		free(params->mtab);
	}
	else if (params->mtab)
		free(params->mtab);
}

void	error_log(char *str, t_params *params, t_map *map)
{
	(void) map;
	(void) params;
	free_params(params);
	free_map(&map);
	perror(str);
	exit (EXIT_SUCCESS);
}

void	check_args_errors(int argc, char **av)
{
	if (argc != 2)
		error_log("Error : invalid number of arguments", NULL, NULL);
	if (ft_rev_strncmp(av[1], ".ber", ft_strlen(av[1])) || !ft_strlen(av[1]))
		error_log("Error : no '.ber' map found", NULL, NULL);
}
