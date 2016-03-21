/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_maj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 17:58:56 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/21 18:09:56 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_min_maj(dev_t rdev)
{
	char	*r;
	int		min;
	int		maj;

	maj = major(rdev);
	min = minor(rdev);
	r = padding_str(ft_itoa(maj), 3, ret_pad(0, 0, RIGHT));
	r = ft_concat(r, ", ", 0);
	r = ft_concat(r, padding_str(ft_itoa(min), 3, ret_pad(0, 1, RIGHT)), 0);
	return (r);
}
