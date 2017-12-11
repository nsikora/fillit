/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:06:24 by nsikora           #+#    #+#             */
/*   Updated: 2017/12/11 10:51:03 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void			internal_get_size(const char *in_file_content,
					unsigned int *out_tetriminos_point_min,
					unsigned int **out_tetriminos_point,
					t_tetris **out_tetriminos_lst)
{
	unsigned int	tetriminos_point_max;
	int				i;
	int				n;

	i = -1;
	n = 0;
	while (++i < 20)
		if (in_file_content[i] == '#')
			(*out_tetriminos_point)[n++] = (unsigned int)i;
	(*out_tetriminos_lst)->height = (((*out_tetriminos_point)[3] / 5) -
			((*out_tetriminos_point)[0] / 5)) + 1;
	n = 0;
	tetriminos_point_max = 0;
	while (n < 4)
	{
		(*out_tetriminos_point)[n] = (*out_tetriminos_point)[n] % 5;
		if ((*out_tetriminos_point)[n] > tetriminos_point_max)
			tetriminos_point_max = (*out_tetriminos_point)[n];
		if ((*out_tetriminos_point)[n] < *out_tetriminos_point_min)
			*out_tetriminos_point_min = (*out_tetriminos_point)[n];
		n = n + 1;
	}
	(*out_tetriminos_lst)->width = tetriminos_point_max -
			*out_tetriminos_point_min + 1;
}

static char			internal_create_tab(unsigned int *tetriminos_point,
					unsigned int tetriminos_point_min,
					t_tetris **out_tetriminos_lst,
					unsigned int i)
{
	unsigned int	n;

	if (!((*out_tetriminos_lst)->tetriminos = malloc(sizeof(char *) *
		(*out_tetriminos_lst)->height)))
		return (FALSE);
	while (i != (*out_tetriminos_lst)->height)
	{
		if (!((*out_tetriminos_lst)->tetriminos[i] =
			malloc((*out_tetriminos_lst)->width)))
			return (FALSE);
		ft_memset((*out_tetriminos_lst)->tetriminos[i], '.',
				(*out_tetriminos_lst)->width);
		i = i + 1;
	}
	i = 0;
	n = 0;
	while (n < 4)
	{
		tetriminos_point[n] = tetriminos_point[n] - tetriminos_point_min;
		if (n != 0 && tetriminos_point[n] <= tetriminos_point[n - 1])
			i = i + 1;
		(*out_tetriminos_lst)->tetriminos[i][tetriminos_point[n]] = '#';
		n = n + 1;
	}
	return (TRUE);
}

static char			internal_stock_file_content(const char *in_file_content,
					const unsigned int in_tetriminos_id,
					t_tetris **out_tetriminos_lst)
{
	unsigned int	*tetriminos_point;
	unsigned int	tetriminos_point_min;

	if (!(*out_tetriminos_lst = malloc(sizeof(t_tetris))))
		return (FALSE);
	if (in_tetriminos_id > TETRIMINOS_MAX_PER_FILE)
		return (FALSE);
	(*out_tetriminos_lst)->number = in_tetriminos_id;
	(*out_tetriminos_lst)->next = NULL;
	if (!(tetriminos_point = malloc(sizeof(unsigned int) * 4)))
		return (FALSE);
	tetriminos_point_min = 4;
	internal_get_size(in_file_content, &tetriminos_point_min,
		&tetriminos_point, out_tetriminos_lst);
	if (!internal_create_tab(tetriminos_point, tetriminos_point_min,
							out_tetriminos_lst, 0))
		return (FALSE);
	free(tetriminos_point);
	if (in_file_content[20] == '\n')
		if (!internal_stock_file_content(in_file_content + 21,
						in_tetriminos_id + 1, &((*out_tetriminos_lst)->next)))
			return (FALSE);
	return (TRUE);
}

static char			internal_ft_read(const char *in_filename,
					t_tetris **out_tetriminos_lst)
{
	int				file_descriptor;
	char			*file_content;
	size_t			file_content_size;
	char			read_buf[READ_COUNT + 1];
	size_t			read_ret;

	if ((file_descriptor = open(in_filename, O_RDONLY)) == -1)
		return (FALSE);
	if (!(file_content = malloc(MALLOC_SIZE)))
		return (FALSE);
	ft_memset(file_content, '\0', READ_COUNT + 1);
	file_content_size = 0;
	while ((read_ret = read(file_descriptor, read_buf, READ_COUNT)) > 0)
	{
		read_buf[read_ret] = '\0';
		if (!ft_check_error(read_buf))
			return (FALSE);
		ft_memcpy(file_content + file_content_size, read_buf,
			(size_t)read_ret);
		file_content_size = file_content_size + read_ret;
	}
	if (read_buf[20] == '\n' || file_content_size == 0
		|| !internal_stock_file_content(file_content, 1, out_tetriminos_lst))
		return (FALSE);
	return (TRUE);
}

extern char			ft_read(const char *in_filename,
					t_tetris **out_tetriminos_lst)
{
	if (out_tetriminos_lst == NULL)
		return (FALSE);
	*out_tetriminos_lst = NULL;
	if (!internal_ft_read(in_filename, out_tetriminos_lst))
		return (FALSE);
	return (TRUE);
}
