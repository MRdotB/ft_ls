/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:18:58 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/22 14:05:29 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	recurse_dir(char *file, t_flag flag)
{
	t_file	*f;

	f = get_t_file_info(file);
	if (flag & F_TIME)
		merge_sort(&f, bytime);
	else
		merge_sort(&f, order);
	if (flag & F_REVS)
		recursive_reverse(&f);
	format_file(f, flag);
	if (flag & F_RECS)
	{
		while (f != NULL)
		{
			if (ft_strcmp(f->name, ".") == 0 || ft_strcmp(f->name, "..") == 0)
			{
				f = f->next;
				continue ;
			}
			if (S_ISDIR(f->fs.st_mode))
				recurse_dir(ft_strjoin(get_path(f->path), f->name), flag);
			f = f->next;
		}
	}
}

int			main(int ac, char **av)
{
	t_flag	flag;
	char	**files;
	int		i;

	i = 0;
	flag = options_check(ac, av);
	files = files_check(ac, av);
	while (files[i])
	{
		recurse_dir(files[i], flag);
		i++;
	}
	return (0);
}
