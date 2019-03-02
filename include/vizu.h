/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vizu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:10:50 by jquivogn          #+#    #+#             */
/*   Updated: 2019/03/02 18:01:59 by jquivogn         ###   ########.fr       */
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

/*
**read.c
*/
int				ft_get_surrend(t_vizu *v, char **line);
int				ft_new_piece(t_vizu *v, char **line, int i);
int				ft_get_info(t_vizu *v, int i);
int				ft_get_piece(t_vizu *v);
int				ft_read_file(t_vizu *v);
/*
**print.c
*/
int				ft_print_map(t_vizu *v);
int				ft_print_piece(t_vizu *v);
int				ft_draw(t_vizu *v);
/*
**use.c
*/
int				ft_create_map(t_vizu *v);
int				ft_print_square(t_vizu *v);
int				ft_print_stat(t_vizu *v);
void			ft_free_tab(char **tab);
/*
**tools.c
*/
int				key_press(int key, void *param);
int				ft_free_and_exit(t_vizu *v);
void			ft_error(char *err);
int				ft_end(t_vizu *v);

#endif
