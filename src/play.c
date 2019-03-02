/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 03:20:28 by jquivogn          #+#    #+#             */
/*   Updated: 2019/03/02 13:27:31 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_sonar(t_map *map, t_piece *piece)
{
	int	i;
	int	j;
	int	check_x;
	int	check_y;

	i = map->range;
	j = 0;
	check_x = map->curr_x + piece->x;
	check_y = map->curr_y + piece->y;
	while (i >= 0)
	{
		if ((check_y + i < map->h_size && check_x + j < map->w_size
		&& map->map[check_y + i][check_x + j] == map->a_letter)
		|| (check_y - i >= 0 && check_x + j < map->w_size
		&& map->map[check_y - i][check_x + j] == map->a_letter)
		|| (check_y + i < map->h_size && check_x - j >= 0
		&& map->map[check_y + i][check_x - j] == map->a_letter)
		|| (check_y - i >= 0 && check_x - j >= 0
		&& map->map[check_y - i][check_x - j] == map->a_letter))
			return (map->range);
		j++;
		i--;
	}
	return (0);
}

int		ft_find_pos(t_map *map, t_piece *piece)
{
	piece->y = -1;
	while (++piece->y < piece->heigth)
	{
		piece->x = -1;
		while (++piece->x < piece->weidth)
		{
			if (piece->piece[piece->y][piece->x] == '*')
			{
				map->range = 1;
				while (map->range <= map->best_range)
				{
					if (ft_sonar(map, piece) != 0
						&& map->range < map->best_range)
					{
						map->best_range = map->range;
						map->pos_x = map->curr_x;
						map->pos_y = map->curr_y;
					}
					map->range += 1;
				}
			}
		}
	}
	return (1);
}

int		ft_check_place(t_map *map, t_piece *p)
{
	map->ancre = 0;
	p->y = -1;
	while (++p->y < p->heigth)
	{
		p->x = -1;
		while (++p->x < p->weidth)
		{
			if (map->curr_y + p->y >= map->h_size || map->curr_x + p->x
			>= map->w_size || map->curr_y + p->y < 0 || map->curr_x + p->x < 0)
			{
				if (p->piece[p->y][p->x] == '*')
					return (0);
				else
					continue ;
			}
			if (map->map[map->curr_y + p->y][map->curr_x + p->x]
			== map->p_letter && p->piece[p->y][p->x] == '*')
				map->ancre += 1;
			if ((map->map[map->curr_y + p->y][map->curr_x + p->x]
			== map->a_letter && p->piece[p->y][p->x] == '*') || map->ancre > 1)
				return (0);
		}
	}
	return (map->ancre);
}

int		ft_search_place(t_map *map, t_piece *piece)
{
	map->curr_y = -piece->cor_y;
	while (map->curr_y < map->h_size)
	{
		map->curr_x = -piece->cor_x;
		while (map->curr_x < map->w_size)
		{
			if (ft_check_place(map, piece) == 1)
				ft_find_pos(map, piece);
			map->curr_x += 1;
		}
		map->curr_y += 1;
	}
	return (1);
}

int		ft_play(t_map *map, t_piece *piece)
{
	if (!ft_search_place(map, piece))
		return (0);
	if (map->pos_x == 0 && map->pos_y == 0)
		if (map->round < 150)
			if (!ft_search_place(map, piece))
				return (0);
	if (map->pos_x == 0 && map->pos_y == 0)
	{
		ft_print_pos(0, 0);
		return (0);
	}
	else
		ft_print_pos(map->pos_x, map->pos_y);
	return (1);
}
