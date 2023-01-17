/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:27:59 by yperonne          #+#    #+#             */
/*   Updated: 2023/01/17 16:31:52 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../get_next_line_bonus/get_next_line_bonus.h"

typedef struct s_param
{
	int				lines;

}	t_param;

typedef struct s_map
{
	char			*map_line;
	struct s_map	*next;
}	t_map;

/* Map initialisation */

t_map	*extract_map(char **argv);

/* Utils */

void	free_map(t_map **map);
void	ft_putstr(char *str);
int		ft_rev_strncmp(const char *str1, const char *str2, size_t n);
/* Errors */

void	check_premap_errors(int argc, char **argv);
void	check_postmap_errors(t_map **map);

#endif