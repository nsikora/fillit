/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:20:02 by cpieri            #+#    #+#             */
/*   Updated: 2017/12/08 13:17:25 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0
# define TETRIMINOS_MAX_PER_FILE (unsigned int)26
# define TETRIMINOS_NB_CHAR (unsigned int)21
# define MALLOC_SIZE (unsigned int)(TETRIMINOS_NB_CHAR*TETRIMINOS_MAX_PER_FILE)
# define READ_COUNT (unsigned int)21

typedef	struct			s_tetris
{
	char				**tetriminos;
	unsigned int		number;
	unsigned int		height;
	unsigned int		width;
	struct s_tetris		*next;
}						t_tetris;

typedef	struct			s_map
{
	char				**map;
	unsigned int		x;
	unsigned int		y;
}						t_map;

void					ft_print_tetri(t_tetris *lst);
void					ft_solve_to_map(t_tetris *lst);
t_tetris				*tetris_lstnew(char *s, unsigned int number);
char					ft_read(const char *in_filename,
							t_tetris **out_tetriminos_lst);
int						ft_check_error(char *read_buf);

#endif
