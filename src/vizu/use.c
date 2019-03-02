/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:10:18 by jquivogn          #+#    #+#             */
/*   Updated: 2019/03/02 17:12:53 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizu.h"

void			ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	while (i-- > 0)
		free(tab[i]);
	free(tab);
}

int				ft_print_square(t_vizu *v)
{
	int	i;
	int	j;
	int	*img;

	img = (int *)v->map.data;
	i = -1;
	j = -1;
	while (++i < 500)
	{
		img[i] = 0xFFFFFF;
		img[500 * 499 + i] = 0xFFFFFF;
	}
	i = 0;
	while (i < (500 * 500) - 500)
	{
		img[i] = 0xFFFFFF;
		img[i + 499] = 0xFFFFFF;
		i += 500;
	}
	return (1);
}

int				ft_print_stat(t_vizu *v)
{
	char *str;

	mlx_string_put(v->e.mlx, v->e.win, 50, 50, 0x0000ff, "Player 1 :");
	mlx_string_put(v->e.mlx, v->e.win, 75, 70, 0x0000ff, v->player_one);
	mlx_string_put(v->e.mlx, v->e.win, 800, 50, 0xff0000, "Player 2 :");
	mlx_string_put(v->e.mlx, v->e.win, 825, 70, 0xff0000, v->player_two);
	mlx_string_put(v->e.mlx, v->e.win, 50, 115, 0xffffff, "Points :");
	str = ft_itoa_base(v->pt_one, 10);
	mlx_string_put(v->e.mlx, v->e.win, 150, 115, 0xffffff, str);
	free(str);
	mlx_string_put(v->e.mlx, v->e.win, 800, 115, 0xffffff, "Points :");
	str = ft_itoa_base(v->pt_two, 10);
	mlx_string_put(v->e.mlx, v->e.win, 900, 115, 0xffffff, str);
	free(str);
	return (1);
}

int				ft_create_map(t_vizu *v)
{
	int		i;

	i = -1;
	if (!(v->piece = (char **)malloc(sizeof(char *)
		* (v->h_piece + 1))))
		return (0);
	v->piece[v->h_piece] = 0;
	while (++i < v->h_piece)
		if (!(v->piece[i] = (char *)malloc(sizeof(char)
			* (v->w_piece + 1))))
			return (0);
	return (1);
}
