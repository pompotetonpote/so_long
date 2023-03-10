/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:00:27 by yperonne          #+#    #+#             */
/*   Updated: 2023/02/21 13:12:59 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_exit(t_params *params, int delta)
{
	if (params->mtab->tab[params->pos + delta] == 'E'
		&& params->pf_c == params->c)
		return (1);
	else if (params->mtab->tab[params->pos + delta] == 'E')
		return (0);
	else
		return (1);
}

void	leftm(t_vars *vars, t_params *params)
{
	if (params->mtab->tab[params->pos - 1] != '1'
		&& check_exit(params, -1))
	{
		pos_analyze(params, -1);
		params->pos--;
		if (params->lmove == 0)
			put_img(vars, LEFT1, params);
		if (params->lmove == 1)
			put_img(vars, STATICL, params);
		if (params->lmove == 2)
			put_img(vars, LEFT2, params);
		if (params->lmove == 3)
		{
			params->lmove = 0;
			put_img(vars, STATICL, params);
		}
		else
			params->lmove++;
		params->moves++;
	}
}

void	rightm(t_vars *vars, t_params *params)
{
	if (params->mtab->tab[params->pos + 1] != '1'
		&& check_exit(params, 1))
	{
		pos_analyze(params, 1);
		params->pos++;
		if (params->rmove == 0)
			put_img(vars, RIGHT1, params);
		if (params->rmove == 1)
			put_img(vars, STATICR, params);
		if (params->rmove == 2)
			put_img(vars, RIGHT2, params);
		if (params->rmove == 3)
		{
			params->rmove = 0;
			put_img(vars, STATICR, params);
		}
		else
			params->rmove++;
		params->moves++;
	}
}

void	downm(t_vars *vars, t_params *params)
{
	if (params->mtab->tab[params->pos + params->line_size] != '1'
		&& check_exit(params, params->line_size))
	{
		pos_analyze(params, params->line_size);
		params->lmove = 0;
		params->rmove = 0;
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
	if (params->mtab->tab[params->pos - params->line_size] != '1'
		&& check_exit(params, -params->line_size))
	{
		pos_analyze(params, -params->line_size);
		params->lmove = 0;
		params->rmove = 0;
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
