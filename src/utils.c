/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julesqvgn <julesqvgn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 05:15:12 by jquivogn          #+#    #+#             */
/*   Updated: 2019/02/22 02:43:13 by julesqvgn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_print_pos(int x, int y)
{
	ft_putnbr(y);
	write(1, " ", 1);
	ft_putnbr(x);
	write(1, "\n", 1);
}

int			ft_error(int error, t_map *map)
{
	if (error == 1)
		write(2, "Parse error\n", 12);
	else if (error == 0)
		write(2, "Error during reading map\n", 25);
	else if (error == -1)
	{
		ft_free_tab(map->map);
		write(2, "Error during reading piece\n", 27);
	}
	return (0);
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