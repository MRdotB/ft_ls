/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 20:59:43 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/15 19:31:03 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_path(char *arg)
{
	char	*r;
	int		i;

	r = ft_strdup(arg);
	if (ft_strncmp("./", r, 2) < 0 && ft_strncmp("/", r, 1) < 0)	
		r = ft_concat(ft_strdup("./"), r);
	i = ft_strlen(r);
	if (r[i - 1] != '/')
		r = ft_concat(r, ft_strdup("/"));
	return (r);
}
