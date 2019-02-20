/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 03:20:28 by jquivogn          #+#    #+#             */
/*   Updated: 2019/02/20 15:44:12 by jquivogn         ###   ########.fr       */
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
	check_x = map->curr_x + piece->act_x;
	check_y = map->curr_y + piece->act_y;
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
	dprintf(2, "                                       <<<< X = %d    Y = %d >>>>\n", map->curr_x, map->curr_y);
	piece->act_y = 0;
	while (piece->act_y < piece->heigth)
	{
		piece->act_x = 0;
		while (piece->act_x < piece->weidth)
		{
			if (piece->piece[piece->act_y][piece->act_x] == '*')
			{
				map->range = 1;
				while (map->range < map->best_range)
				{
					if (ft_sonar(map, piece) != 0)
					{
						map->best_range = map->range;
						dprintf(2, "range max = %d   X = %d    Y = %d\n", map->best_range, map->curr_x, map->curr_y);
						map->pos_x = map->curr_x;
						map->pos_y = map->curr_y;
					}
					map->range += 1;
				}
			}
			piece->act_x += 1;
		}
		piece->act_y += 1;
	}
	//dprintf(2, "--->range max = %d\n", map->best_range);
	return (1);
}

int		ft_check_place(t_map *map, t_piece *piece)
{
	int	ancre;

	ancre = 0;
	piece->act_y = 0;
	while (piece->act_y < piece->heigth)
	{
		piece->act_x = 0;
		while (piece->act_x < piece->weidth)
		{
			if (map->curr_y + piece->act_y < map->h_size && map->curr_x + piece->act_x < map->w_size)
			{
				if (map->map[map->curr_y + piece->act_y][map->curr_x + piece->act_x] == map->p_letter
				&& piece->piece[piece->act_y][piece->act_x] == '*')
				{
					dprintf(2, "=> X = %d + %d   Y = %d + %d    | %c |\n", map->curr_x, piece->act_x, map->curr_y, piece->act_y, map->map[map->curr_y + piece->act_y][map->curr_y + piece->act_x]);
					dprintf(2, "-- %s\n", map->map[12]);
					ancre += 1;
				}
				// if (map->map[map->curr_y + piece->act_y][map->curr_y + piece->act_x] != '.'
				// && map->map[map->curr_y + piece->act_y][map->curr_y + piece->act_x] != map->p_letter)
				// 	return (ft_check_place(map, piece));
			}
			piece->act_x += 1;
		}
		piece->act_y += 1;
	}
	if (ancre == 1)
		ft_find_pos(map, piece);
	return (ancre);
}

int		ft_search_place(t_map *map, t_piece *piece)
{
	dprintf(2, "==========================\n");
	while (map->curr_y < map->h_size)
	{
		map->curr_x = 0;
		while (map->curr_x < map->w_size)
		{
			ft_check_place(map, piece);
			map->curr_x += 1;
		}
		map->curr_y += 1;
	}
	return (1);
}

int		ft_play(t_map *map, t_piece *piece)
{
	dprintf(2, "-- %s\n", map->map[12]);
	if (!ft_search_place(map, piece))
		return (0);
	dprintf(2, "X = %d    Y = %d\n", map->pos_x, map->pos_y);
	if (map->finish == 1)
	{
		ft_print_pos(0, 0);
		return (0);
	}
	else
		ft_print_pos(map->pos_x, map->pos_y);
	return (1);
}
