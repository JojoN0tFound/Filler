/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:59:19 by julesqvgn         #+#    #+#             */
/*   Updated: 2019/03/02 17:11:56 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizu.h"

static int		ft_choose_color(char c, t_vizu *v)
{
	if (c == '.')
		return (0x0);
	if (c == 'O')
		return (0x0000ff);
	if (c == 'X')
		return (0xff0000);
	if (c == 'o')
	{
		v->player = 2;
		return (0x00ffff);
	}
	if (c == 'x')
	{
		v->player = 1;
		return (0xff00ff);
	}
	return (0);
}

static void		ft_color_case(t_vizu *v, int index_y, int index_x, char *line)
{
	int		x;
	int		y;
	int		size_w;
	int		size_h;
	int		*img;

	img = (int *)v->map.data;
	y = index_y * (int)(500 / v->h_map);
	x = index_x * (int)(500 / v->w_map);
	size_w = (int)(500 / v->w_map) + x;
	size_h = (int)(500 / v->h_map) + y;
	while (y < size_h)
	{
		x = index_x * (int)(500 / v->w_map);
		while (x < size_w)
		{
			if (x >= 0 && x < 500 && y >= 0 && y < 500)
				img[y * 500 + x] = ft_choose_color(line[index_x], v);
			x++;
		}
		y++;
	}
}

int				ft_print_piece(t_vizu *v)
{
	int		i;

	i = -1;
	while (++i < v->h_piece)
	{
		if (v->player == 1 || v->player == 3)
			mlx_string_put(v->e.mlx, v->e.win,
				100, 250 + i * 15, 0xffffff, v->piece[i]);
		else if (v->player == 2 || v->player == 4)
			mlx_string_put(v->e.mlx, v->e.win,
				850, 250 + i * 15, 0xffffff, v->piece[i]);
	}
	if (v->player == 1)
		v->pt_one > 0 ? v->pt_two += 1 : 1;
	else
		v->pt_one += 1;
	ft_free_tab(v->piece);
	return (1);
}

int				ft_print_map(t_vizu *v)
{
	int		i;
	int		j;
	int		c;
	char	*line;

	i = -1;
	c = 0;
	while (++i < v->h_map)
	{
		if (get_next_line(0, &line) <= 0)
			return (0);
		while (line[c] && (line[c] == ' '
			|| (line[c] >= '0' && line[c] <= '9')))
			c++;
		j = -1;
		while (line[++j])
			ft_color_case(v, i, j, line + c);
		free(line);
	}
	ft_print_square(v);
	mlx_put_image_to_window(v->e.mlx, v->e.win, v->map.ptr, 250, 75);
	return (1);
}

int				ft_draw(t_vizu *v)
{
	int	ret;
	int	i;

	i = 0;
	ret = 0;
	if (v->start != 2)
	{
		ret = ft_get_info(v, i);
		if (ret != 3)
		{
			mlx_put_image_to_window(v->e.mlx, v->e.win, v->info.ptr, 0, 0);
			ft_print_map(v);
			ft_get_piece(v);
			ft_print_piece(v);
			ft_print_stat(v);
		}
	}
	return (1);
}
