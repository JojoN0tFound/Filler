/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julesqvgn <julesqvgn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 05:15:12 by jquivogn          #+#    #+#             */
/*   Updated: 2019/03/04 10:20:50 by julesqvgn        ###   ########.fr       */
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

int			ft_error(int error, t_map *map, t_piece *piece)
{
	if (error == 1)
		write(2, "Parse error\n", 12);
	else if (error == 0)
	{
		ft_free_tab(map->map);
		write(2, "Error during reading map\n", 25);
	}
	else if (error == -1 || error == -2)
	{
		error == -2 ? ft_free_tab(piece->piece) : 1;
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

int			ft_take_line(void)
{
	char *str;

	if (get_next_line(0, &str) <= 0)
		return (0);
	free(str);
	return (1);
}

int			ft_check_line(char **line, t_map *map)
{
	int		c;
	int		i;
	char	*str;

	c = 0;
	i = 0;
	str = *line;
	while (str[i] && (str[i] == ' ' || (str[i] >= '0' && str[i] <= '9')))
		i++;
	while (str[c + i])
	{
		if (str[c + i] != map->p_letter && str[c + i] != map->a_letter
			&& str[c + i] != '.')
		{
			free(*line);
			return (0);
		}
		c++;
	}
	if ((int)ft_strlen(str + i) != map->w_size)
	{
		free(*line);
		return (0);
	}
	return (1);
}
