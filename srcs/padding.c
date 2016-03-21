/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 10:38:07 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/21 18:00:19 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_numlen(int n)
{
	if (n < 0)
		return (ft_numlen(n * -1) + 1);
	if (n >= 10)
		return (ft_numlen(n / 10) + 1);
	return (1);
}

t_pad			ret_pad(int prepad, int postpad, int direction)
{
	t_pad	p;

	p.prepad = prepad;
	p.postpad = postpad;
	p.direction = direction;
	return (p);
}

void			max_padding(int padding[], t_file *f, t_flag flag)
{
	int	i;

	i = 0;
	while (i < 5)
		padding[i++] = 0;
	while (f != NULL)
	{
		if (!(flag & F_ADOT) && f->name[0] == '.')
		{
			f = f->next;
			continue ;
		}
		if (padding[0] < ft_numlen(f->fs.st_nlink))
			padding[0] = ft_numlen(f->fs.st_nlink);
		if (padding[1] < (int)ft_strlen(get_user(f->fs.st_uid)))
			padding[1] = (int)ft_strlen(get_user(f->fs.st_uid));
		if (padding[2] < (int)ft_strlen(get_group(f->fs.st_gid)))
			padding[2] = (int)ft_strlen(get_group(f->fs.st_gid));
		if (padding[3] < ft_numlen(f->fs.st_size))
			padding[3] = ft_numlen(f->fs.st_size);
		padding[4] += f->fs.st_blocks;
		f = f->next;
	}
}

char			*padding_str(char *str, int size, t_pad p)
{
	char	*r;
	int		i;
	int		j;
	int		len;

	r = ft_strnew(size + p.prepad + p.postpad + 1);
	len = ft_strlen(str);
	ft_memset(r, ' ', size + p.prepad + p.postpad);
	if (p.direction == LEFT)
	{
		i = p.prepad;
		j = -1;
		while (++j < len)
			r[i++] = str[j];
	}
	if (p.direction == RIGHT)
	{
		i = size - 1 + p.prepad;
		while (len > 0)
			r[i--] = str[--len];
	}
	ft_memdel((void**)&str);
	return (r);
}
