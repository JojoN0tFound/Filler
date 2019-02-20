/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 03:19:24 by jquivogn          #+#    #+#             */
/*   Updated: 2019/02/20 15:56:44 by jquivogn         ###   ########.fr       */
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
		dprintf(2, "create map\n");
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
		dprintf(2, "create piece\n");
	}
	return (1);
}

int		ft_get_info(t_map *map, t_piece *piece)
{
	char	*line;
	int		i;

	i = 0;
	if (get_next_line(0, &line) <= 0)/*player id*/
		return (0);
	map->p_id = ft_atoi(&line[10]);
	// free(line);
	map->p_letter = map->p_id == 1 ? 'O' : 'X';
	map->a_letter = map->p_id == 2 ? 'O' : 'X';
	if (get_next_line(0, &line) <= 0)/*map size*/
		return (0);
	while (line[i] && !ft_isdigit(*(line + i)))
			i++;
	map->h_size = ft_atoi(line + i);
	while (line[i] && ft_isdigit(*(line + i)))
			i++;
	map->w_size = ft_atoi(line + i);
	// free(line);
	if (!ft_create_map(0, map, piece))
		return (0);
	// if (get_next_line(0, &line) <= 0)/*map absciss*/
	// 	return (0);
	// free(line);
	return (1);
}

int		ft_get_map(t_map *map)
{
	char	*line;
	int		i;

	i = 0;
	//if (get_next_line(0, &line) <= 0)/*map size*/
	//	return (0);
	//free(line);
	if (get_next_line(0, &line) <= 0)/*map absciss*/
		return (0);
	//free(line);
	while (i < map->h_size)
	{
		if (get_next_line(0, &line) <= 0)/*map*/
			return (0);
		while (*line && (*line == ' ' || (*line >= '0' && *line <= '9' )))
			line++;
		map->map[i] = ft_strcpy(map->map[i], line);
		dprintf(2, "%s\n", map->map[i]);
		// free(line);
		i++;
	}
	i = 0;
	dprintf(2, "map : x = %d y = %d\n", map->w_size, map->h_size);
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
				piece->x = j;
				piece->y = i;
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
	int		l;

	i = 0;
	l = 0;
	if (get_next_line(0, &line) <= 0)/*piece size*/
		return (0);
	while (line[l] && !ft_isdigit(line[l]))
		l++;
	piece->heigth = ft_atoi(line + l);
	while (line[l] && ft_isdigit(line[l]))
		l++;
	piece->weidth = ft_atoi(line + l);
	// free(line);
	if (!ft_create_map(1, map, piece))
		return (0);
	while (i < piece->heigth)
	{
		if (get_next_line(0, &line) <= 0)/*piece*/
			return (0);
		piece->piece[i] = ft_strcpy(piece->piece[i], line);
		dprintf(2, "%s\n", piece->piece[i]);
		// free(line);
		i++;
	}
	dprintf(2, "piece : x = %d y = %d\n", piece->weidth, piece->heigth);
	ft_get_corner(piece);
	return (1);
}
