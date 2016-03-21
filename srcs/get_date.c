/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_date.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:48:32 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/21 18:53:09 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		get_date_free(char **split, char **hsplit)
{
	int	i;

	i = 0;
	while (split && split[i])
		free(split[i++]);
	free(split);
	i = 0;
	while (hsplit && hsplit[i])
		free(hsplit[i++]);
	free(hsplit);
}

static t_string	*get_date_ex(t_string *r, struct timespec t, char **split)
{
	int		current_time;
	char	**hsplit;

	hsplit = NULL;
	current_time = time(NULL);
	if (current_time - t.tv_sec > SIXMONTH ||
			current_time - t.tv_sec < -(SIXMONTH))
	{
		ft_string_append(r, " ");
		split[4][4] = '\0';
		ft_string_append(r, split[4]);
	}
	else
	{
		hsplit = ft_strsplit(split[3], ':');
		ft_string_append(r, hsplit[0]);
		ft_string_append(r, ":");
		ft_string_append(r, hsplit[1]);
	}
	ft_string_append(r, " ");
	get_date_free(split, hsplit);
	return (r);
}

t_string		*get_date(struct timespec t)
{
	char		**split;
	t_string	*r;

	r = ft_string_new(13);
	split = ft_strsplit(ctime(&t.tv_sec), ' ');
	ft_string_append(r, split[1]);
	ft_string_append(r, " ");
	if (ft_strlen(split[2]) == 1)
		ft_string_append(r, " ");
	ft_string_append(r, split[2]);
	ft_string_append(r, " ");
	return (get_date_ex(r, t, split));
}
