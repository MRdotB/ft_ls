/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 10:38:07 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/17 15:47:01 by bchaleil         ###   ########.fr       */
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

int			*max_padding(t_file *f, t_flag flag)
{
	int	*padding;

	padding = (int*)ft_memalloc(sizeof(int) * 5);
	while (f != NULL)
	{
		if (flag ^ F_ADOT && f->name[0] == '.')
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
		f = f->next;
	}
	padding[4] = 0;
	return (padding);
}

char		*padding_str(char *str, int size, t_pad p)
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
			r[i++] = str[j];;
	}
	if (p.direction == RIGHT)
	{
		i = size - 1 + p.prepad;
		while (len > 0)
		{
			len--;
			r[i] = str[len];
			i--;
		}
	}
	return (r);
}
