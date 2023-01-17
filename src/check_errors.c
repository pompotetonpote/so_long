/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pompote <pompote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:55:36 by yperonne          #+#    #+#             */
/*   Updated: 2023/01/17 22:01:33 by pompote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	error_log(char *str)
{
	ft_putstr(str);
	exit (1);
}

void	check_args_errors(int argc, char **av)
{
	if (argc != 2)
		error_log("Error : invalid number of arguments");
	if (ft_rev_strncmp(av[1], ".ber", ft_strlen(av[1])) || !ft_strlen(av[1]))
		error_log("Error : no '.ber' map found");
}
