/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:27:59 by yperonne          #+#    #+#             */
/*   Updated: 2023/01/18 17:07:38 by yperonne         ###   ########.fr       */
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

typedef struct s_elems
{
	int			e;
	int			c;
	int			p;
	int			first_line;
	size_t		line_size;
}	t_elems;

typedef struct s_map
{
	char			*map_line;
	struct s_map	*next;
}	t_map;

/* Map initialisation */

t_map	*extract_map(char **argv);

/* Utils */
char	*ft_strchr(const char *str, int a);
void	free_map(t_map **map);
void	ft_putstr(char *str);
int		ft_rev_strncmp(const char *str1, const char *str2, size_t n);
int		ft_lstsize(t_map *lst);
/* Errors */

void	check_args_errors(int argc, char **argv);
void	map_parsing(t_map **map);
int		error_log(char *str);
int		check_squared_and_lines(t_map **map, t_elems **elems);

/*test map*/
void	linkedlist_check(int i, t_map **map);

#endif