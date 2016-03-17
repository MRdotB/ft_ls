/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 20:34:53 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/17 18:54:35 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	format_file(t_file *f, t_flag flag)
{
	char	*r;
	int		*padding;

	padding = NULL;
	if (flag & F_LIST)
		padding = max_padding(f, flag);
	while (f != NULL)
	{
        if (!(flag & F_ADOT) && f->name[0] == '.')
		{
			f = f->next;
			continue ;
		}
		if (flag & F_LIST)
		{
			r = get_mode(f->fs.st_mode, ft_strjoin(get_path(f->path), f->name));			
			ft_putstr(r);
			r = padding_str(ft_itoa(f->fs.st_nlink), padding[0], ret_pad(0, 0, RIGHT));			
			ft_putstr(r);
			r = padding_str(get_user(f->fs.st_uid), padding[1], ret_pad(1, 2, LEFT));			
			ft_putstr(r);
			r = padding_str(get_group(f->fs.st_gid), padding[2], ret_pad(0, 2, LEFT));			
			ft_putstr(r);
			r = padding_str(ft_itoa(f->fs.st_size), padding[3], ret_pad(0, 1, RIGHT));			
			ft_putstr(r);
			r = get_date(f->fs.st_mtimespec);
			ft_putstr(r);
			ft_putendl(f->name);
		}
		f = f->next;
	}
}
