/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainvizu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:09:01 by jquivogn          #+#    #+#             */
/*   Updated: 2019/02/22 20:53:47 by jquivogn         ###   ########.fr       */
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

	img = (int *)v->img.data;
	y = index_y * (500 / v->h_map);
	x = index_x * (500 / v->w_map);
	size_w = 500 / v->w_map + x;
	size_h = 500 / v->h_map + y;
	while (y < size_h)
	{
		x = index_x * (500 / v->w_map);
		while (x < size_w)
		{
			if (x >= 0 && x < 500 && y >= 0 && y < 500)
				img[y * 500 + x] = ft_choose_color(line[index_x], v);
			x++;
		}
		y++;
	}
}

void			ft_error(char *err)
{
	ft_putendl(err);
	exit(0);
}

int		ft_get_info(t_vizu *v)
{
	int		i;
	char	*line;

	i = 0;
	if (v->start == 1)
	{
		if (get_next_line(0, &line) <= 0)
			return (-1);
		// free(line);
	}
	if (get_next_line(0, &line) <= 0)
		return (0);
	while (line[i] && !ft_isdigit(*(line + i)))
			i++;
	v->h_map = ft_atoi(line + i);
	while (line[i] && ft_isdigit(*(line + i)))
			i++;
	v->w_map = ft_atoi(line + i);
	// free(line);
	if (get_next_line(0, &line) <= 0)
			return (-1);
	// free(line);
	v->start = 1;
	return (1);
}

int		ft_print_piece(t_vizu *v)
{
	int		i;
	char	*line;

	i = 0;
	if (get_next_line(0, &line) <= 0)
		return (-1);
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	v->h_piece = ft_atoi(line + i);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	v->w_piece = ft_atoi(line + i);
	// free(line);
	i = -1;
	while (++i < v->h_piece)
	{
		if (get_next_line(0, &line) <= 0)
			return (-1);
		mlx_string_put(v->e.mlx, v->e.win, 100, 150 + i * 5, 0xffffff, line);
		// free(line);
	}
	return (1);
}

int		ft_print_map(t_vizu *v)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (i < v->h_map)
	{
		if (get_next_line(0, &line) <= 0)
			return (0);
		while (*line && (*line == ' ' || (*line >= '0' && *line <= '9' )))
			line++;
		j = -1;
		while (line[++j])
			ft_color_case(v, i, j, line);
		// free(line);
		i++;
	}
	return (1);
}

int		ft_draw(t_vizu *v)
{
	ft_get_info(v);
	ft_print_map(v);
	ft_print_piece(v);
	mlx_put_image_to_window(v->e.mlx, v->e.win, v->img.ptr, 600, 100);
	return (1);
}

int		ft_read_file(void)
{
	int		i;
	char	*line;

	i = 0;
	while (i < 9)
	{
		if (get_next_line(0, &line) <= 0)
			return (-1);
		// free(line);
		i++;
	}
	return (1);
}

static int	ft_init_mlx(t_env *e, t_img *img)
{
	if (!(e->mlx = mlx_init()))
		return (-1);
	if (!(e->win = mlx_new_window(e->mlx, WIN_W, WIN_H, "FILLER")))
	{
		free(e->mlx);
		return (-1);
	}
	if (!(img->ptr = mlx_new_image(e->mlx, 500, 500)))
	{
		free(e->mlx);
		free(e->win);
		return (-1);
	}
	if (!(img->data = mlx_get_data_addr(img->ptr, &(img->bpp),
					&(img->sl), &(img->endian))))
	{
		free(e->mlx);
		free(e->win);
		free(img->data);
		return (-1);
	}
	return (1);
}

int		ft_free_and_exit(t_vizu *v)
{
	mlx_destroy_image(v->e.mlx, v->img.ptr);
	mlx_destroy_window(v->e.mlx, v->e.win);
	free(v->e.mlx);
	exit(0);
	return (0);
}

int		ft_init(t_vizu *v)
{
	v->player = 0;
	v->w_map = 0;
	v->h_map = 0;
	v->w_piece = 0;
	v->h_piece = 0;
	v->s_round = 0;
	v->round = 0;
	v->start = 0;
	return (1);
}

int		key_press(int key, void *param)
{
	t_vizu	*v;

	v = (t_vizu *)param;
	if (key == KEY_ESC)
		return (ft_free_and_exit(v));
	if (key == KEY_ENTER)
		return (ft_draw(v));
	return (1);
}

int		main(void)
{
	t_vizu	v;

	if (ft_init_mlx(&v.e, &v.img) == -1
				|| ft_read_file() == -1)
			ft_error("Error");
	ft_init(&v);
	ft_draw(&v);
	mlx_hook(v.e.win, 2, 1L << 2, &key_press, (void *)&v);
	mlx_loop(v.e.mlx);
	return (0);
}