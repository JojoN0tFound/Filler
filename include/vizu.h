/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vizu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:10:50 by jquivogn          #+#    #+#             */
/*   Updated: 2019/02/22 19:30:15 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIZU_H
# define VIZU_H
# define WIN_W 1000
# define WIN_H 700
# include "mlx.h"
# include "libft.h"

# define KEY_ESC 53
# define KEY_ENTER 36

typedef struct	s_env
{
	void		*mlx;
	void		*win;
}				t_env;

typedef struct	s_img
{
	void		*ptr;
	char		*data;
	int			bpp;
	int			sl;
	int			endian;
}				t_img;

typedef struct	s_vizu
{
	t_env		e;
	t_img		img;
	int			player;
	int			w_map;
	int			h_map;
	int			w_piece;
	int			h_piece;
	int			s_round;
	int			round;
	int			start;
}				t_vizu;

#endif