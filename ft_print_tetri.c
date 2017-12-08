/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:36:16 by nsikora           #+#    #+#             */
/*   Updated: 2017/12/08 12:46:30 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

extern void			ft_print_tetri(t_tetris *lst)
{
	unsigned int	i;

	i = 0;
	while (lst)
	{
		while (i < lst->height)
		{
			ft_putnstr(lst->tetriminos[i], lst->width);
			ft_putchar('\n');
			i++;
		}
		ft_putchar('\n');
		lst = lst->next;
		i = 0;
	}
}
