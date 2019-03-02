/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vizu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julesqvgn <julesqvgn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:10:50 by jquivogn          #+#    #+#             */
/*   Updated: 2019/02/26 21:52:40 by julesqvgn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIZU_H
# define VIZU_H
# define WIN_W 1000
# define WIN_H 700
# include "../../../../minilibx_macos/mlx.h"
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
	t_img		map;
	t_img		info;
	char		**piece;
	char		*player_one;
	char		*player_two;
	int			player;
	int			pt_one;
	int			pt_two;
	int			w_map;
	int			h_map;
	int			w_piece;
	int			h_piece;
	int			start;
	int			end;
}				t_vizu;


int				ft_end(t_vizu *v);
int				ft_print_map(t_vizu *v);
int				ft_print_piece(t_vizu *v);
int				ft_read_file(t_vizu *v);
int				ft_get_info(t_vizu *v);
int				ft_draw(t_vizu *v);
int				ft_get_piece(t_vizu *v);

#endif