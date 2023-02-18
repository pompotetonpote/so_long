/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:00:27 by yperonne          #+#    #+#             */
/*   Updated: 2023/02/18 18:29:18 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	leftm(t_vars *vars, t_params *params)
{
	if (params->mtab->tab[params->pos - 1] != '1')
	{
		put_img(vars, FLOOR, params);
		params->pos--;
		if (params->lmove == 0)
		{
			params->lmove++;
			printf("%d\n", params->lmove);
			put_img(vars, LEFT1, params);
		}
		if (params->lmove++ == 1)
			put_img(vars, STATICL, params);
		if (params->lmove == 2)
		{
			params->lmove = 0;
			put_img(vars, LEFT2, params);
		}
		params->moves++;
	}
}

void	rightm(t_vars *vars, t_params *params)
{
	if (params->mtab->tab[params->pos + 1] != '1')
	{
		put_img(vars, FLOOR, params);
		params->pos++;
		if (params->rmove++ == 0)
			put_img(vars, RIGHT1, params);
		if (params->rmove++ == 1)
			put_img(vars, STATICR, params);
		if (params->rmove == 2)
		{
			params->rmove = 0;
			put_img(vars, RIGHT2, params);
		}
		params->moves++;
	}
}

void	downm(t_vars *vars, t_params *params)
{
	printf("position :%lu, value : %d\n", params->pos + params->line_size, params->mtab->tab[params->pos + params->line_size]);
	if (params->mtab->tab[params->pos + params->line_size] != '1')
	{
		params->lmove = 0;
		params->rmove = 0;
		put_img(vars, FLOOR, params);
		printf("params->pos bef: %d\n", params->pos);
		params->pos = params->pos + params->line_size;
		printf("params->pos aft : %d\n", params->pos);
		if (params->dmove == 0)
			put_img(vars, FRONT1, params);
		if (params->dmove == 1)
		{
			params->dmove = 0;
			put_img(vars, FRONT2, params);
		}
		params->moves++;
	}
}

void	upm(t_vars *vars, t_params *params)
{
	if (params->mtab->tab[params->pos - params->line_size] != '1')
	{
		params->lmove = 0;
		params->rmove = 0;
		put_img(vars, FLOOR, params);
		params->pos = params->pos - params->line_size;
		if (params->umove == 0)
			put_img(vars, BACK1, params);
		if (params->umove == 1)
		{
			params->lmove = 0;
			put_img(vars, BACK2, params);
		}
		params->moves++;
	}
}


