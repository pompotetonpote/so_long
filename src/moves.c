/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeye <yeye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:00:27 by yperonne          #+#    #+#             */
/*   Updated: 2023/02/19 09:59:17 by yeye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	leftm(t_vars *vars, t_params *params)
{
	if (params->mtab->tab[params->pos - 1] != '1')
	{
		pos_analyze(params, -1);
		put_img(vars, FLOOR, params);
		params->pos--;
		if (params->lmove == 0)
			put_img(vars, LEFT1, params);
		if (params->lmove == 1)
			put_img(vars, STATICL, params);
		if (params->lmove == 2)
		{
			params->lmove = 0;
			put_img(vars, LEFT2, params);
		}
		else
			params->lmove++;
		params->moves++;
	}
}

void	rightm(t_vars *vars, t_params *params)
{
	if (params->mtab->tab[params->pos + 1] != '1')
	{
		pos_analyze(params, +1);
		put_img(vars, FLOOR, params);
		params->pos++;
		if (params->rmove == 0)
			put_img(vars, RIGHT1, params);
		if (params->rmove == 1)
			put_img(vars, STATICR, params);
		if (params->rmove == 2)
		{
			params->rmove = 0;
			put_img(vars, RIGHT2, params);
		}
		else
			params->rmove++;
		params->moves++;
	}
}

void	downm(t_vars *vars, t_params *params)
{
	if (params->mtab->tab[params->pos + params->line_size] != '1')
	{
		pos_analyze(params, +params->line_size);
		params->lmove = 0;
		params->rmove = 0;
		put_img(vars, FLOOR, params);
		params->pos = params->pos + params->line_size;
		if (params->dmove == 0)
		{
			params->umove = 1;
			put_img(vars, FRONT1, params);
		}
		if (params->dmove == 1)
		{
			params->dmove = 0;
			put_img(vars, FRONT2, params);
		}
		else
			params->dmove++;
		params->moves++;
	}
}

void	upm(t_vars *vars, t_params *params)
{
	if (params->mtab->tab[params->pos - params->line_size] != '1')
	{
		pos_analyze(params, -params->line_size);
		params->lmove = 0;
		params->rmove = 0;
		put_img(vars, FLOOR, params);
		params->pos = params->pos - params->line_size;
		if (params->umove == 0)
		{
			params->dmove = 1;
			put_img(vars, BACK1, params);
		}
		if (params->umove == 1)
		{
			params->umove = 0;
			put_img(vars, BACK2, params);
		}
		else
			params->umove++;
		params->moves++;
	}
}


