/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_date.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:48:32 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/18 13:31:19 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_date(struct timespec t)
{
	int		current_time;
	char	**split;
	char	**hsplit;
	char	*r;

	split = ft_strsplit(ctime(&t.tv_sec), ' ');
	current_time = time(NULL);
	r = ft_strjoin(split[1], " ");
	if (ft_strlen(split[2]) == 1)
		r = ft_concat(r, " ", 1);
	r = ft_concat(r, split[2], 1);
	r = ft_concat(r, " ", 1);
	if (current_time - t.tv_sec > SIXMONTH ||
			current_time - t.tv_sec < -(SIXMONTH))
	{
		r = ft_concat(r, " ", 1);
		split[4][4] = '\0';
		r = ft_concat(r, split[4], 1);
	}
	else
	{
		hsplit = ft_strsplit(split[3], ':');
		r = ft_concat(r, hsplit[0], 1);
		r = ft_concat(r, ":", 1);
		r = ft_concat(r, hsplit[1], 1);
	}
	r = ft_concat(r, " ", 1);
	return (r);
}
