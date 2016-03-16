/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:31:24 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/16 14:46:15 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	order(t_file *a, t_file *b)
{
	return (ft_strcmp(b->name, a->name) > 0);
}

int	reverse(t_file *a, t_file *b)
{
	return (ft_strcmp(b->name, a->name) < 0);
}
