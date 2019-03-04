/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julesqvgn <julesqvgn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:53:31 by julesqvgn         #+#    #+#             */
/*   Updated: 2019/03/04 10:20:34 by julesqvgn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>

typedef struct	s_map
{
	char	p_letter;
	char	a_letter;
	int		p_id;
	int		w_size;
	int		h_size;
	int		curr_x;
	int		curr_y;
	int		pos_x;
	int		pos_y;
	int		round;
	int		finish;
	int		range;
	int		best_range;
	int		ancre;
	char	**map;
}				t_map;

typedef struct	s_piece
{
	int		weidth;
	int		heigth;
	int		x;
	int		y;
	int		cor_x;
	int		cor_y;
	char	**piece;
}				t_piece;

/*
**play.c
*/
int				ft_search_place(t_map *map, t_piece *piece);
int				ft_find_pos(t_map *map, t_piece *piece);
int				ft_sonar(t_map *map, t_piece *piece);
int				ft_check_place(t_map *map, t_piece *p);
int				ft_play(t_map *map, t_piece *piece);
/*
**get.c
*/
int				ft_create_map(int c, t_map *map, t_piece *piece);
int				ft_get_info(t_map *map, t_piece *piece);
int				ft_get_map(t_map *map);
int				ft_get_piece(t_map *map, t_piece *piece);
/*
**utils.c
*/
int				ft_check_line(char **line, t_map *map);
int				ft_take_line(void);
void			ft_print_pos(int x, int y);
int				ft_error(int error, t_map *map, t_piece *piece);
void			ft_free_tab(char **tab);

#endif
