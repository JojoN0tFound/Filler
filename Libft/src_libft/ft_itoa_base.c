/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 21:04:46 by jquivogn          #+#    #+#             */
/*   Updated: 2019/01/16 21:04:57 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	res_size(long long value, int base)
{
	int		i;

	i = 0;
	if (!(value))
		return (1);
	while (value)
	{
		value = value / (long long)base;
		i++;
	}
	return (i);
}

static char			*fill_base(int base)
{
	char	*base_arr;
	int		i;

	i = 0;
	if (!(base_arr = (char *)malloc(sizeof(char) * (base + 1))))
		return (NULL);
	while (i <= 9 && i < base)
	{
		base_arr[i] = i + '0';
		i++;
		while (i > 9 && i < base)
		{
			base_arr[i] = i - 10 + 'a';
			i++;
		}
	}
	base_arr[i] = '\0';
	return (base_arr);
}

static char			*neg_int(long long value)
{
	char	*res;
	int		i;

	i = res_size(value, 10) + 1;
	if (!(res = (char *)malloc(sizeof(char) * i)))
		return (NULL);
	res[i] = '\0';
	res[0] = '-';
	i--;
	while (i > 0)
	{
		res[i] = (value % 10) * -1 + '0';
		value = value / 10;
		i--;
	}
	return (res);
}

char				*ft_itoa_base(long long value, int base)
{
	char				*base_arr;
	char				*base_res;
	int					i;
	unsigned long long	uns;

	uns = ft_abs(value);
	i = res_size(uns, base);
	if (value < 0 && base == 10)
	{
		base_res = neg_int(value);
		return (base_res);
	}
	if (!(base_arr = fill_base(base)))
		return (NULL);
	if (!(base_res = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	base_res[i--] = '\0';
	while (i >= 0)
	{
		base_res[i] = base_arr[uns % (unsigned long long)base];
		uns = uns / (unsigned long long)base;
		i--;
	}
	free(base_arr);
	return (base_res);
}
