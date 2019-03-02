/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:13:33 by jquivogn          #+#    #+#             */
/*   Updated: 2019/03/02 17:13:56 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizu.h"

int			ft_end(t_vizu *v)
{
	free(v->player_one);
	free(v->player_two);
	v->start = 2;
	return (3);
}

void		ft_error(char *err)
{
	ft_putendl(err);
	exit(0);
}

int			ft_free_and_exit(t_vizu *v)
{
	mlx_destroy_image(v->e.mlx, v->map.ptr);
	mlx_destroy_image(v->e.mlx, v->info.ptr);
	mlx_destroy_window(v->e.mlx, v->e.win);
	free(v->e.mlx);
	exit(0);
	return (0);
}

int			key_press(int key, void *param)
{
	t_vizu	*v;

	v = (t_vizu *)param;
	ft_bzero(v->info.data, 1000 * 700);
	if (key == KEY_ESC)
		return (ft_free_and_exit(v));
	if (key == KEY_ENTER && v->start != 2)
		return (ft_draw(v));
	return (1);
}
