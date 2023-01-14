/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pompote <pompote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:27:59 by yperonne          #+#    #+#             */
/*   Updated: 2023/01/13 00:51:11 by pompote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../mlx-linux/mlx.h"
# include "../get_next_line_bonus/get_next_line_bonus.h"


typedef struct s_param
{
    struct s_param  *next;
}   t_param;

#endif