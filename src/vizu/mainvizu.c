/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainvizu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:09:01 by jquivogn          #+#    #+#             */
/*   Updated: 2019/03/02 17:57:08 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizu.h"

static int	ft_init(t_vizu *v)
{
	v->player = 1;
	v->w_map = 0;
	v->h_map = 0;
	v->pt_one = 0;
	v->pt_two = 0;
	v->w_piece = 0;
	v->h_piece = 0;
	v->start = 0;
	v->end = 0;
	return (1);
}

static int	ft_init_mlx(t_env *e, t_img *map)
{
	if (!(e->mlx = mlx_init()))
		return (-1);
	if (!(e->win = mlx_new_window(e->mlx, WIN_W, WIN_H, "FILLER")))
	{
		free(e->mlx);
		return (-1);
	}
	if (!(map->ptr = mlx_new_image(e->mlx, 500, 500)))
	{
		free(e->mlx);
		free(e->win);
		return (-1);
	}
	if (!(map->data = mlx_get_data_addr(map->ptr, &(map->bpp),
					&(map->sl), &(map->endian))))
	{
		free(e->mlx);
		free(e->win);
		free(map->ptr);
		return (-1);
	}
	return (1);
}

static int	ft_init_img_info(t_img *info, t_env *e, t_img *map)
{
	if (!(info->ptr = mlx_new_image(e->mlx, 1000, 700)))
	{
		free(e->mlx);
		free(e->win);
		free(map->data);
		free(map->ptr);
		return (-1);
	}
	if (!(info->data = mlx_get_data_addr(map->ptr, &(map->bpp),
					&(map->sl), &(map->endian))))
	{
		free(e->mlx);
		free(e->win);
		free(map->data);
		free(map->ptr);
		free(info->ptr);
		return (-1);
	}
	return (1);
}

int			main(void)
{
	t_vizu	v;

	if (ft_init_mlx(&v.e, &v.map) == -1
				|| ft_init_img_info(&v.info, &v.e, &v.map) == -1
				|| ft_read_file(&v) == -1)
		ft_error("Error");
	ft_init(&v);
	ft_draw(&v);
	mlx_hook(v.e.win, 2, 1L << 2, &key_press, (void *)&v);
	mlx_loop(v.e.mlx);
	return (0);
}
