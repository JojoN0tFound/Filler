/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 03:19:24 by jquivogn          #+#    #+#             */
/*   Updated: 2019/03/02 22:20:22 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			ft_create_map(int c, t_map *map, t_piece *piece)
{
	int	i;

	i = -1;
	if (c == 0)
	{
		if (!(map->map = (char **)malloc(sizeof(char *) * (map->h_size + 1))))
			return (0);
		map->map[map->h_size] = 0;
		while (++i < map->h_size)
			if (!(map->map[i] = (char *)malloc(sizeof(char)
				* (map->w_size + 1))))
				return (0);
	}
	else
	{
		if (!(piece->piece = (char **)malloc(sizeof(char *)
			* (piece->heigth + 1))))
			return (0);
		piece->piece[piece->heigth] = 0;
		while (++i < piece->heigth)
			if (!(piece->piece[i] = (char *)malloc(sizeof(char)
				* (piece->weidth + 1))))
				return (0);
	}
	return (1);
}

int			ft_get_info(t_map *map, t_piece *piece)
{
	char	*line;
	int		i;

	i = 0;
	if (get_next_line(0, &line) <= 0)
		return (0);
	map->p_id = ft_atoi(&line[10]);
	free(line);
	map->p_letter = map->p_id == 1 ? 'O' : 'X';
	map->a_letter = map->p_id == 2 ? 'O' : 'X';
	if (get_next_line(0, &line) <= 0)
		return (0);
	while (line[i] && !ft_isdigit(*(line + i)))
		i++;
	map->h_size = ft_atoi(line + i);
	while (line[i] && ft_isdigit(*(line + i)))
		i++;
	map->w_size = ft_atoi(line + i);
	free(line);
	if ((map->w_size <= 0 && map->h_size <= 0) || (map->p_id != 1 && map->p_id
	!= 2))
		return (0);
	if (!ft_create_map(0, map, piece))
		return (0);
	return (1);
}

int			ft_get_map(t_map *map)
{
	char	*str;
	int		i;
	int		c;

	i = -1;
	c = 0;
	if (map->round != 0)
		if (!ft_take_line())
			return (0);
	if (get_next_line(0, &str) <= 0)
		return (0);
	free(str);
	while (++i < map->h_size)
	{
		if (get_next_line(0, &str) <= 0)
			return (0);
		while (str[c] && (str[c] == ' ' || (str[c] >= '0' && str[c] <= '9')))
			c++;
		if (!ft_check_line(&str, map))
			return (0);
		map->map[i] = ft_strcpy(map->map[i], str + c);
		free(str);
	}
	return (1);
}

static int	ft_get_corner(t_piece *piece, int c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < piece->heigth)
	{
		j = 0;
		while (j < piece->weidth)
		{
			if (piece->piece[i][j] != '.' && piece->piece[i][j] != '*')
				return (-1);
			if (piece->piece[i][j] == '*' && c != -1)
			{
				c = -1;
				piece->cor_x = j;
				piece->cor_y = i;
			}
			j++;
		}
		i++;
	}
	return (1);
}

int			ft_get_piece(t_map *map, t_piece *piece)
{
	char	*line;
	int		i;

	i = 0;
	if (get_next_line(0, &line) <= 0)
		return (-1);
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	piece->heigth = ft_atoi(line + i);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	piece->weidth = ft_atoi(line + i);
	free(line);
	if (!ft_create_map(1, map, piece))
		return (-1);
	i = -1;
	while (++i < piece->heigth)
	{
		if (get_next_line(0, &line) <= 0)
			return (-1);
		piece->piece[i] = ft_strcpy(piece->piece[i], line);
		free(line);
	}
	return (ft_get_corner(piece, i));
}
