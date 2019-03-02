/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:58:21 by julesqvgn         #+#    #+#             */
/*   Updated: 2019/03/02 17:12:56 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizu.h"

int		ft_get_piece(t_vizu *v)
{
	char	*line;
	int		i;

	i = 0;
	if (get_next_line(0, &line) <= 0)
		return (-1);
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	v->h_piece = ft_atoi(line + i);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	v->w_piece = ft_atoi(line + i);
	free(line);
	if (!ft_create_map(v))
		return (-1);
	i = -1;
	while (++i < v->h_piece)
	{
		if (get_next_line(0, &line) <= 0)
			return (-1);
		v->piece[i] = ft_strcpy(v->piece[i], line);
		free(line);
	}
	return (1);
}

int		ft_new_piece(t_vizu *v, char **line, int i)
{
	v->player = v->player == 2 ? 3 : 4;
	v->end += 1;
	while ((*line)[i] && !ft_isdigit((*line)[i]))
		i++;
	v->h_piece = ft_atoi(*line + i);
	while (*line[i] && ft_isdigit(*line[i]))
		i++;
	v->w_piece = ft_atoi(*line + i);
	free(*line);
	if (!ft_create_map(v))
		return (-1);
	i = -1;
	while (++i < v->h_piece)
	{
		if (get_next_line(0, line) <= 0)
			return (-1);
		v->piece[i] = ft_strcpy(v->piece[i], *line);
		free(*line);
	}
	i = 0;
	ft_print_piece(v);
	ft_get_info(v, i);
	return (2);
}

int		ft_get_surrend(t_vizu *v, char **line)
{
	int	i;

	i = 0;
	free(*line);
	v->end == 1 ? v->end += 1 : 1;
	if (get_next_line(0, line) <= 0)
		return (-1);
	if (ft_strstr(*line, "Piece"))
		return (ft_new_piece(v, line, i));
	else if (ft_strstr(*line, "fin:"))
	{
		free(*line);
		return (ft_end(v));
	}
	else if (ft_strstr(*line, "Plateau"))
	{
		free(*line);
		if (get_next_line(0, line) <= 0)
			return (0);
		free(*line);
		v->end == 2 ? ft_print_map(v) : 1;
		return (v->end == 2 ? ft_end(v) : 1);
	}
	return (1);
}

int		ft_get_info(t_vizu *v, int i)
{
	char	*line;

	if (v->start == 1)
	{
		if (get_next_line(0, &line) <= 0)
			return (-1);
		v->player <= 2 ? v->player = v->player + 1 % 2 : 1;
		if (ft_strstr(line, "[0, 0]") || ft_strstr(line, "error"))
			return (ft_get_surrend(v, &line));
		free(line);
	}
	if (get_next_line(0, &line) <= 0)
		return (0);
	i = 0;
	while (line[i] && !ft_isdigit(*(line + i)))
		i++;
	v->h_map = ft_atoi(line + i);
	while (line[i] && ft_isdigit(*(line + i)))
		i++;
	v->w_map = ft_atoi(line + i);
	free(line);
	if (get_next_line(0, &line) <= 0)
		return (-1);
	free(line);
	return ((v->start = 1));
}

int		ft_read_file(t_vizu *v)
{
	int		i;
	int		c;
	char	*line;

	i = -1;
	while (++i < 9)
	{
		if (get_next_line(0, &line) <= 0)
			return (-1);
		if (i == 5 || i == 7)
		{
			c = 1;
			while (line[c - 1] != '/')
				c++;
			if (!(i == 5 ? v->player_one = ft_strdup(line + c) : (char *)1))
				return (-1);
			if (!(i == 7 ? v->player_two = ft_strdup(line + c) : (char *)1))
				return (-1);
		}
		free(line);
	}
	v->player_one[ft_strlen(v->player_one) - 7] = '\0';
	v->player_two[ft_strlen(v->player_two) - 7] = '\0';
	return (1);
}
