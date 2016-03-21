/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:18:58 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/21 20:16:50 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
/*
static void delete_list(t_file **head_ref)
{
	t_file *current;
	t_file *next;

	current = *head_ref;
	while (current != NULL) 
	{
		next = current->next;
		free(current->name);
		free(current->path);
		free(current);
		current = next;
	}
	*head_ref = NULL;
}
*/
static void	recurse_dir(char *file, t_flag flag)
{
	t_file	*f;
	t_file	*head_ref;

	f = get_t_file_info(file);
	head_ref = f;
	if (flag & F_TIME)
		merge_sort(&f, bytime);
	else
		merge_sort(&f, order);
	if (flag & F_REVS)
		recursive_reverse(&f);
	if (flag & F_RECS && flag & F_LAST)
		flag ^= F_LAST;
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
//	delete_list(&head_ref);
}

int			main(int ac, char **av)
{
	t_flag	flag;
	char	**files;
	int		i;
	int		files_nb;

	i = 0;
	files_nb = 0;
	flag = options_check(ac, av);
	files = files_check(ac, av);
	while (files[files_nb])
		files_nb++;
	if (files_nb > 1 || flag & F_RECS)
		flag |= F_PATH;
	while (files[i])
	{
		if (i + 1 == files_nb)
			flag |= F_LAST;
		recurse_dir(files[i], flag);
		i++;
	}
	return (0);
}
