/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 13:09:39 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/22 13:20:38 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_color(mode_t st_mode)
{
	if (S_ISBLK(st_mode))
		return (RESET);
	else if (S_ISCHR(st_mode))
		return (GREEN);
	else if (S_ISDIR(st_mode))
		return (YELLOW);
	else if (S_ISLNK(st_mode))
		return (RED);
	else if (S_ISSOCK(st_mode))
		return (MAGENTA);
	else if (S_ISFIFO(st_mode))
		return (CYAN);
	else if (S_ISREG(st_mode))
		return (BLUE);
	return (RESET);
}
