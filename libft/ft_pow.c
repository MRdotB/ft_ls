/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 14:20:43 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/07 13:21:53 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_pow(int nb, unsigned int power)
{
	if (power == 0)
		return (1);
	else
		return (nb * ft_pow(nb, power - 1));
}
