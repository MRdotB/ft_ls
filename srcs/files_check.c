/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:01:34 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/16 16:33:51 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		**files_check(int ac, char **av)
{
	int		i;
	int		j;
	char	**r;

	if (ac == 1 || (ac == 2 && ft_strcmp(av[1], ".") == 0))
		return (ft_strsplit(". ", ' '));
	i = 1;
	while (av[i] && av[i][0] == '-')
		i++;
	if (i == ac)
		return (ft_strsplit(". ", ' '));
	j = 0;
	while (av[i + j])
		j++;
	if (!(r = (char**)ft_memalloc(sizeof(char*) * (j + 1))))
		return (NULL);
	j = 0;
	while (av[i + j])
	{
		r[j] = ft_strdup(av[i + j]);
		j++;
	}
	r[j] = NULL;
	return (r);
}
