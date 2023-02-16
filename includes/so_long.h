/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pompote <pompote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:27:59 by yperonne          #+#    #+#             */
/*   Updated: 2023/02/16 00:54:47 by pompote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../get_next_line_bonus/get_next_line_bonus.h"
# include "../img/imgxpm.h"
# if defined(__APPLE__) && defined(__MACH__)
#  include "../mlx/mlx.h"
#  define ESC 53
# else
#  include "../mlx-linux/mlx.h"
#  define ESC 66
# endif

typedef struct s_tab
{
	int	*tab;
}	t_tab;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
}	t_vars;

typedef struct s_map
{
	char			*map_line;
	struct s_map	*next;
}	t_map;

// typedef struct s_img
// {
// 	void	*mlx_img;
// 	int		w;
// 	int		h;
// }	t_img;

typedef struct s_params
{
	int			e;
	int			pf_e;
	int			c;
	int			pf_c;
	int			p;
	int			step;
	int			first_line;
	int			map_line_nbr;
	int			tab_tot_size;
	int			lines;
	int			pos;
	int			pos_x;
	int			pos_y;
	int			w;
	int			h;
	void		*img;
	// t_img		wall;
	t_tab		*mtab;
	size_t		line_size;
}	t_params;

/* Map initialisation */

t_map		*extract_map(char **argv);
t_params	*init_elems(void);

/* Utils */
char		*ft_strchr(const char *str, int a);
void		free_map(t_map **map);
void		ft_putstr(char *str);
int			ft_rev_strncmp(const char *str1, const char *str2, size_t n);
int			ft_lstsize(t_map *lst);

/* Linked List Utils*/
t_map		*new_map_line(char *line);
t_map		*get_last_map_element(t_map *map);
t_map		*get_bf_last_map_element(t_map *map);
void		*add_new_map_line(t_map **map, t_map *new_map_line_elem);
void		ft_lstadd_back(t_map **map, t_map *new_map_line_elem);

/* Errors */

void		check_args_errors(int argc, char **argv);
void		map_parsing(t_map **map, t_params *elems);
int			error_log(char *str);
int			check_squared_and_lines(t_map **map, t_params **elems);
void		check_path(t_map **map, t_params	*elems);
void		print_tab(t_tab *tab, t_params *elems);
int			find_spawn(t_tab *mtab, int spawn, t_params *elems);
void		increm_elem(t_tab *maptab, int x, t_params *nb_elems);
void		trackm(t_tab *mtab, int spa, t_tab *tr_tb, t_params *elems);

/* Graphic */

void		window_init(t_vars *vars, t_params *params);

/*test map*/
void		linkedlist_check(t_map **map);
void		put_game(t_vars *vars, t_params *params);

#endif