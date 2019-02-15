/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:53:31 by julesqvgn         #+#    #+#             */
/*   Updated: 2019/02/14 15:09:26 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>

typedef struct	s_map
{
	int		p_id;
	int		size_x;
	int		size_y;
	int		current_x;
	int		current_y;
	int		last_x;
	int		last_y;
	char	letter;
	char	**map;
}				t_map;

typedef struct	s_piece
{
	int		weidth;
	int		heigth;
	int		x;
	int		y;
	char	**piece;
}				t_piece;

#endif