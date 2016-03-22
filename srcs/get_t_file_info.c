/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_t_file_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 13:43:35 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/21 19:27:03 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_file	*new_elem(char *name, char *path, struct stat fs)
{
	t_file		*f;

	if (!(f = ft_memalloc(sizeof(t_file))))
		return (NULL);
	f->name = name;
	f->path = path;
	f->fs = fs;
	f->next = NULL;
	return (f);
}

static t_file	*push_front(t_file *lst, t_file *el)
{
	if (lst == NULL)
		return (el);
	else
		el->next = lst;
	return (el);
}

t_file			*get_t_file_info(char *dir_name)
{
	struct dirent	*p_dirent;
	DIR				*p_dir;
	t_file			*list;
	struct stat		fs;

	list = NULL;
	p_dir = opendir(dir_name);
	if (p_dir == NULL)
	{
		ls_perror(dir_name);
		return (NULL);
	}
	while ((p_dirent = readdir(p_dir)) != NULL)
	{
		if (lstat(ft_strjoin(get_path(dir_name),
						p_dirent->d_name), &fs) == -1)
			ls_perror("stat fail");
		else
			list = push_front(list, new_elem(ft_strdup(p_dirent->d_name),
						dir_name, fs));
	}
	closedir(p_dir);
	return (list);
}
