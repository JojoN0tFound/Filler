/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julesqvgn <julesqvgn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:59:19 by julesqvgn         #+#    #+#             */
/*   Updated: 2019/02/26 22:09:38 by julesqvgn        ###   ########.fr       */
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

void		ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	while (i-- > 0)
		free(tab[i]);
	free(tab);
}

int		ft_print_piece(t_vizu *v)
{
	int		i;

	i = -1;
	while (++i < v->h_piece)
	{
		if (v->player == 1 || v->player == 3)
			mlx_string_put(v->e.mlx, v->e.win, 100, 250 + i * 15, 0xffffff, v->piece[i]);
		else if (v->player == 2 || v->player == 4)
			mlx_string_put(v->e.mlx, v->e.win, 850, 250 + i * 15, 0xffffff, v->piece[i]);
	}
	if (v->player == 1)
		v->pt_one > 0 ? v->pt_two += 1 : 1;
	else
		v->pt_one += 1;
	ft_free_tab(v->piece);
	return (1);
}

int		ft_print_square(t_vizu *v)
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

int		ft_print_map(t_vizu *v)
{
	int		i;
	int		j;
	char	*line;

	i = -1;
	while (++i < v->h_map)
	{
		if (get_next_line(0, &line) <= 0)
			return (0);
		while (*line && (*line == ' ' || (*line >= '0' && *line <= '9' )))
			line++;
		j = -1;
		while (line[++j])
			ft_color_case(v, i, j, line);
	}
	ft_print_square(v);
	mlx_put_image_to_window(v->e.mlx, v->e.win, v->map.ptr, 250, 75);
	// free(line);
	return (1);
}

int		ft_print_stat(t_vizu *v)
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

int		ft_draw(t_vizu *v)
{
	int	ret;

	ret = 0;
	if (v->start != 2)
	{
		ret = ft_get_info(v);
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
