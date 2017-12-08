/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:54:51 by nsikora           #+#    #+#             */
/*   Updated: 2017/12/08 10:39:53 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_check_place(char *s)
{
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '\n' && s[i] != '.' && s[i] != '#')
			return (FALSE);
		if (s[i] == '\n' && i % 5 != 4 && i != 20)
			return (FALSE);
		if ((s[i] == '#' || s[i] == '.') && i % 5 == 4)
			return (FALSE);
		if (s[i] == '#')
			nb++;
		i++;
	}
	if (s[i - 1] != '\n')
		return (FALSE);
	if (nb != 4)
		return (FALSE);
	return (TRUE);
}

static int	ft_check_nb_connection(char *s)
{
	int		i;
	int		connect;

	i = 0;
	connect = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '#' && s[i + 1] == '#')
			connect++;
		if (s[i] == '#' && s[i + 5] == '#')
			connect++;
		if (s[i] == '#' && i >= 1 && s[i - 1] == '#')
			connect++;
		if (s[i] == '#' && i >= 5 && s[i - 5] == '#')
			connect++;
		i++;
	}
	if (connect == 6 || connect == 8)
		return (TRUE);
	return (FALSE);
}

extern int	ft_check_error(char *s)
{
	if (ft_check_place(s) == FALSE)
		return (FALSE);
	if (ft_check_nb_connection(s) == FALSE)
		return (FALSE);
	return (TRUE);
}
