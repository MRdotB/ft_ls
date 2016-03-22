/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:48:53 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/22 16:16:19 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_flag	raise_flag(char c)
{
	if (c == 'l')
		return (F_LIST);
	else if (c == 'R')
		return (F_RECS);
	else if (c == 'a')
		return (F_ADOT);
	else if (c == 'r')
		return (F_REVS);
	else if (c == 't')
		return (F_TIME);
	else if (c == 'G')
		return (F_COLO);
	else if (c == '1')
		return (0);
	else
		return (F_ERRO);
}

t_flag			options_check(int ac, char **av)
{
	t_flag	flag;
	int		i;
	int		j;

	flag = F_NULL;
	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-' && ft_strlen(av[i]) > 1)
		{
			j = 1;
			while (av[i][j])
			{
				flag |= raise_flag(av[i][j]);
				if (flag & F_ERRO)
					usage(av[i][j]);
				j++;
			}
		}
		else
			break ;
		i++;
	}
	return (flag);
}
