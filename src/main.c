/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:57:12 by julesqvgn         #+#    #+#             */
/*   Updated: 2019/02/13 14:52:58 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_info(t_map *map, t_piece *piece)
{
	(void)map;
	(void)piece;
}

void	ft_init(t_map *map, t_piece *piece)
{
	(void)map;
	(void)piece;
}

int		main(void)
{
	t_map	map;
	t_piece	piece;

	ft_init(&map, &piece);
	get_info(&map, &piece);
	return (0);
}