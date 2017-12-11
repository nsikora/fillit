/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:14:39 by nsikora           #+#    #+#             */
/*   Updated: 2017/12/11 13:02:38 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fillit.h"

int		main(int ac, char **av)
{
	t_tetris	*tetris;

	if (ac != 2)
	{
		ft_putendl("./fillit source_file");
		return (1);
	}
	if (!ft_read(av[1], &tetris))
	{
		ft_putendl("error");
		return (1);
	}
	ft_solve_to_map(tetris);
	return (0);
}
