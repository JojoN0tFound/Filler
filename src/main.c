/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:57:12 by julesqvgn         #+#    #+#             */
/*   Updated: 2019/02/14 20:47:03 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_create_map(int c, t_map *map, t_piece *piece)
{
	int	i;

	i = -1;
	if (c == 0)
	{
		if (!(map->map = (char **)malloc(sizeof(char *) * (map->size_y + 1))))
			return (0);
		map->map[map->size_y] = 0;
		while (++i < map->size_y)
			if (!(map->map[i] = (char *)malloc(sizeof(char) * (map->size_x + 1))))
				return (0);
	}
	else
	{
		if (!(piece->piece = (char **)malloc(sizeof(char *) * (piece->heigth + 1))))
			return (0);
		piece->piece[piece->heigth] = 0;
		while (++i < piece->heigth)
			if (!(piece->piece[i] = (char *)malloc(sizeof(char) * (piece->weidth + 1))))
				return (0);
	}
	return (1);
}

void	get_info(t_map *map, t_piece *piece)
{
	char	*line;

	if (get_next_line(0, &line) == 1)/*player id*/
	{
		if (ft_strstr(line, ".filler"))
		{
			if (ft_strstr(line, "jquivogn.filler"))
				map->p_id = 1;
			else
				map->p_id = 2;
			free(line);
		}
		get_next_line(0, &line);
		free(line);
	}
}

void	get_map(t_map *map, t_piece *piece)
{
	char	*line;
	int		i;

	i = 0;
	get_next_line(0, &line);/*coup precedent*/
	map->letter = line[6];
	while (!ft_isdigit(*line))
		line++;
	map->last_y = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	map->last_x = ft_atoi(line);
	free(line);
	get_next_line(0, &line); /* size plateau*/
	while (!ft_isdigit(*line))
		line++;
	map->size_y = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	map->size_x = ft_atoi(line);
	free(line);
	get_next_line(0, &line); /*ligne correspondant a l axe des abscisses*/
	free(line);
	if (!ft_create_map(0, map, piece))
		return ;
	while (i < map->size_y)
	{
		if (get_next_line(0, &line) == -1) /*lecture map*/
			return ;
		map->map[i] = ft_strcpy(map->map[i], line);
		free(line);
		i++;
	}
	i = 0;
	get_next_line(0, &line); /*size piece*/
	while (!ft_isdigit(*line))
		line++;
	piece->heigth = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	piece->weidth = ft_atoi(line);
	free(line);
	if (!ft_create_map(1, map, piece))
		return ;
	while (i < piece->heigth)
	{
		if (get_next_line(0, &line) == -1) /*lecture map*/
			return ;
		piece->piece[i] = ft_strcpy(piece->piece[i], line);
		free(line);
		i++;
	}
}

void	ft_init(t_map *map, t_piece *piece)
{
	map->p_id = 0;
	map->letter = 0;
	map->size_x = 0;
	map->size_y = 0;
	map->current_y = 0;
	map->current_x = 0;
	piece->weidth = 0;
	piece->heigth = 0;
	piece->x = 0;
	piece->y = 0;
}

int		main(void)
{
	t_map	map;
	t_piece	piece;

	ft_init(&map, &piece);
	get_info(&map, &piece);
	while (1)
	{

	}
	return (0);
}