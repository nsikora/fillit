/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:37:15 by nsikora           #+#    #+#             */
/*   Updated: 2017/12/08 15:56:16 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_map		*init_map(t_map *map, unsigned int len_map)
{
	unsigned int	i;

	i = 0;
	if (!(map = malloc(sizeof(t_map))))
		return (NULL);
	if (!(map->map = malloc(sizeof(char*) * (len_map + 1))))
		return (NULL);
	while (i < len_map)
	{
		if (!(map->map[i] = (char*)malloc(sizeof(char) * (len_map + 1))))
			return (NULL);
		map->map[i] = ft_memset(map->map[i], '.', len_map);
		i++;
	}
	map->map[i] = NULL;
	map->x = 0;
	map->y = 0;
	return (map);
}

static int			check_place(t_tetris *lst, t_map *map, int x, int y)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < lst->height)
	{
		while (j < lst->width)
		{
			if (lst->tetriminos[i][j] == '#' && map->map[x + i][y + j] != '.')
				return (1);
			if (lst->tetriminos[i][j] == '#' && map->map[x + i][y + j] == '.')
				map->map[x + i][y + j] = lst->number + 'A' - 1;
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

static void			clean_place(t_tetris *lst, t_map *map,
						unsigned int x, unsigned int y)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < lst->height)
	{
		while (j < lst->width)
		{
			if (lst->tetriminos[i][j] == '#'
					&& map->map[x + i][y + j] == (char)(lst->number + 'A' - 1))
				map->map[x + i][y + j] = '.';
			j++;
		}
		i++;
		j = 0;
	}
}

static int			backtrack(t_tetris *lst, t_map *map, unsigned int len_map)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	if (lst == NULL)
		return (1);
	while (x <= (len_map - lst->height))
	{
		while (y <= (len_map - lst->width))
		{
			if (check_place(lst, map, x, y) == 0)
			{
				if (backtrack(lst->next, map, len_map))
					return (1);
			}
			clean_place(lst, map, x, y);
			y++;
		}
		x++;
		y = 0;
	}
	return (0);
}

void				ft_solve_to_map(t_tetris *lst)
{
	t_map			*map;
	unsigned int	len_map;
	unsigned int	x;

	map = NULL;
	x = 0;
	ft_print_tetri(lst);
	len_map = ft_sqrt(lst->number * 4);
	while (len_map < lst->height || len_map < lst->width)
		len_map++;
	map = init_map(map, len_map);
	while (backtrack(lst, map, len_map) == 0)
	{
		len_map++;
		free(map);
		map = init_map(map, len_map);
	}
	while (map->map[x])
		ft_putendl(map->map[x++]);
	free(map);
}
