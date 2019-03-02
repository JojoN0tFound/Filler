/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julesqvgn <julesqvgn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 03:19:24 by jquivogn          #+#    #+#             */
/*   Updated: 2019/02/24 05:01:26 by julesqvgn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_create_map(int c, t_map *map, t_piece *piece)
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

int		ft_get_info(t_map *map, t_piece *piece)
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

int		ft_get_map(t_map *map)
{
	char	*line;
	int		i;

	i = 0;
	if (map->round != 0)
	{
		if (get_next_line(0, &line) <= 0)
			return (0);
		free(line);
	}
	if (get_next_line(0, &line) <= 0)
		return (0);
	free(line);
	while (i < map->h_size)
	{
		if (get_next_line(0, &line) <= 0)
			return (0);
		while (*line && (*line == ' ' || (*line >= '0' && *line <= '9' )))
			line++;
		map->map[i] = ft_strcpy(map->map[i], line);
		//free(line);
		i++;
	}
	return (1);
}

static void	ft_get_corner(t_piece *piece)
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
			if (piece->piece[i][j] == '*')
			{
				piece->cor_x = j;
				piece->cor_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int		ft_get_piece(t_map *map, t_piece *piece)
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
	ft_get_corner(piece);
	return (1);
}
