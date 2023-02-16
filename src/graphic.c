/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pompote <pompote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:42:19 by yperonne          #+#    #+#             */
/*   Updated: 2023/02/16 23:08:34 by pompote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	window_init(t_vars *vars, t_params *params)
{
	printf("window_init\n");
	params->lines = params->lines / 2;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, (params->line_size) * 64, (params->lines) * 64, "so_long");
}

void	put_img(t_vars *vars, char *str, t_params *p)
{
	p->pos_x = p->pos % p->line_size;
	p->pos_y = p->pos / p->line_size;
	printf("pos_x : %d, pos_y : %d, line_size : %zu\n", p->pos_x, p->pos_y, p->line_size);
	p->img = mlx_xpm_file_to_image(vars->mlx, str, &p->w, &p->h);
	mlx_put_image_to_window(vars->mlx, vars->win, p->img, p->pos_x * 64, p->pos_y * 64);
}

void	put_init(t_vars *vars, t_params *params)
{
	if (params->mtab->tab[params->pos] == '1')
		put_img(vars, WALL, params);
	if (params->mtab->tab[params->pos] == 'P')
		put_img(vars, STATICL, params);
	if (params->mtab->tab[params->pos] == 'E')
		put_img(vars, VORTEX, params);
	if (params->mtab->tab[params->pos] == 'C')
		put_img(vars, BLOCK, params);
	if (params->mtab->tab[params->pos] == '0')
		put_img(vars, FLOOR, params);
}

void	put_game(t_vars *vars, t_params *params)
{
	while (params->pos < ((int)params->line_size * params->lines))
	{
		printf("%d : %d\n", params->pos, (int)params->line_size * params->lines);
		put_init(vars, params);
		params->pos++;
	}
}
