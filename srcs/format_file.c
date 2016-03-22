/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 20:34:53 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/22 14:01:53 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	format_file_link(t_file *f, t_string *r, t_flag flag)
{
	char		*linkname;

	if (S_ISLNK(f->fs.st_mode))
	{
		linkname = ft_strnew(f->fs.st_size);
		if (readlink(ft_strjoin(get_path(f->path), f->name),
					linkname, f->fs.st_size + 1) == -1)
		{
			perror("readlink");
			exit(EXIT_FAILURE);
		}
		ft_string_append(r, f->name);
		ft_string_append(r, " -> ");
		ft_string_append(r, linkname);
		ft_memdel((void**)&linkname);
	}
	else
	{
		if (flag & F_COLO)
			ft_string_append(r, get_color(f->fs.st_mode));
		ft_string_append(r, f->name);
		if (flag & F_COLO)
			ft_string_append(r, RESET);
	}
}

void	format_file_ex3(t_file *f, t_string *r, int padding[], t_flag flag)
{
	t_string	*date;

	if (S_ISBLK(f->fs.st_mode) || S_ISCHR(f->fs.st_mode))
		ft_string_append(r, get_min_maj(f->fs.st_rdev));
	else
		ft_string_append(r, padding_str(ft_itoa(f->fs.st_size),
					padding[3], ret_pad(0, 1, RIGHT)));
	date = get_date(f->fs.st_mtimespec);
	ft_string_append(r, date->data);
	ft_string_free(date);
	format_file_link(f, r, flag);
}

void	format_file_ex2(t_file *f, t_string *r, int padding[])
{
	char		*tmp;
	char		*path_name;

	path_name = ft_strjoin(get_path(f->path), f->name);
	tmp = get_mode(f->fs.st_mode, path_name);
	ft_string_append(r, tmp);
	free(path_name);
	free(tmp);
	ft_string_append(r, padding_str(ft_itoa(f->fs.st_nlink),
				padding[0], ret_pad(0, 0, RIGHT)));
	ft_string_append(r, padding_str(get_user(f->fs.st_uid),
				padding[1], ret_pad(1, 2, LEFT)));
	ft_string_append(r, padding_str(get_group(f->fs.st_gid),
				padding[2], ret_pad(0, 2, LEFT)));
}

void	format_file_ex1(t_file *f, t_flag flag, int padding[])
{
	t_string	*r;

	r = ft_string_new(256);
	if (!(flag & F_ADOT) && f->name[0] == '.')
		return ;
	if (flag & F_LIST)
	{
		format_file_ex2(f, r, padding);
		format_file_ex3(f, r, padding, flag);
	}
	else
	{
		if (flag & F_COLO)
			ft_string_append(r, get_color(f->fs.st_mode));
		ft_string_append(r, f->name);
		if (flag & F_COLO)
			ft_string_append(r, RESET);
	}
	ft_string_append(r, "\n");
	ft_putstr(r->data);
	ft_string_free(r);
}

void	format_file(t_file *f, t_flag flag)
{
	int			padding[5];

	if (f && flag & F_RECS)
	{
		ft_putstr("\n");
		ft_putstr(f->path);
		ft_putstr(":\n");
	}
	max_padding(padding, f, flag);
	if (f && flag & F_LIST && padding[4] != 0)
	{
		ft_putstr("total ");
		ft_putendl(ft_itoa(padding[4]));
	}
	while (f != NULL)
	{
		format_file_ex1(f, flag, padding);
		f = f->next;
	}
}
