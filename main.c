/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:14:39 by cpieri            #+#    #+#             */
/*   Updated: 2017/12/08 10:22:09 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
