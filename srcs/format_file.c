/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 20:34:53 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/16 21:41:09 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	format_file(t_file *f, t_flag flag)
{
	while (f != NULL)
	{
        if (flag ^ F_ADOT && f->name[0] == '.')
		{
			f = f->next;
			continue ;
		}
		ft_putendl(f->name);
		f = f->next;
	}
}
