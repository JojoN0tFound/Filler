/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:53:31 by julesqvgn         #+#    #+#             */
/*   Updated: 2019/02/20 12:33:39 by jquivogn         ###   ########.fr       */
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
	char	**map;
}				t_map;

typedef struct	s_piece
{
	int		weidth;
	int		heigth;
	int		x;
	int		y;
	int		act_x;
	int		act_y;
	char	**piece;
}				t_piece;

/*
*play.c
*/
int				ft_search_place(t_map *map, t_piece *piece);
int				ft_find_pos(t_map *map, t_piece *piece);
int				ft_sonar(t_map *map, t_piece *piece);
int				ft_check_place(t_map *map, t_piece *piece);
int				ft_play(t_map *map, t_piece *piece);
/*
*get.c
*/
int				ft_create_map(int c, t_map *map, t_piece *piece);
int				ft_get_info(t_map *map, t_piece *piece);
int				ft_get_map(t_map *map);
int				ft_get_piece(t_map *map, t_piece *piece);
/*
*print_coor.c
*/
void			ft_print_pos(int x, int y);

#endif