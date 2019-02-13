/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julesqvgn <julesqvgn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:53:31 by julesqvgn         #+#    #+#             */
/*   Updated: 2019/02/12 20:39:14 by julesqvgn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/include/libft.h"
# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>

typedef struct	s_map
{
	int		p_id;
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