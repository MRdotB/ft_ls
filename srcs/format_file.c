/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 20:34:53 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/18 20:51:04 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	format_file(t_file *f, t_flag flag)
{
	char	*r;
	char	*linkname;
	int		padding[5];

	if (flag & F_LIST)
	{
		max_padding(padding, f, flag);
		ft_putstr("total ");
		ft_putnbrnl(padding[4]);
	}
	while (f != NULL)
	{
		if (!(flag & F_ADOT) && f->name[0] == '.')
		{
			f = f->next;
			continue ;
		}
		if (flag & F_LIST)
		{
			ft_putstr(get_mode(f->fs.st_mode, ft_strjoin(get_path(f->path), f->name)));
			ft_putstr(padding_str(ft_itoa(f->fs.st_nlink), padding[0], ret_pad(0, 0, RIGHT)));
			ft_putstr(padding_str(get_user(f->fs.st_uid), padding[1], ret_pad(1, 2, LEFT)));
			ft_putstr(padding_str(get_group(f->fs.st_gid), padding[2], ret_pad(0, 2, LEFT)));
			if (S_ISBLK(f->fs.st_mode) || S_ISCHR(f->fs.st_mode))
				ft_putstr(get_min_maj(f->fs.st_rdev));
			else
				ft_putstr(padding_str(ft_itoa(f->fs.st_size), padding[3], ret_pad(0, 1, RIGHT)));
			r = get_date(f->fs.st_mtimespec);
			ft_putstr(r);
			if (S_ISLNK(f->fs.st_mode))
			{
				linkname = ft_strnew(f->fs.st_size);
				if (readlink(ft_strjoin(get_path(f->path), f->name), linkname, f->fs.st_size + 1) == -1)
				{
					perror("readlink");
					exit(EXIT_FAILURE);
				}
				ft_putstr(f->name);
				ft_putstr(" -> ");
				ft_putendl(linkname);
				ft_memdel((void**)&linkname);
			}
			else
				ft_putendl(f->name);
		}
		else
			ft_putendl(f->name);
		f = f->next;
	}
}
