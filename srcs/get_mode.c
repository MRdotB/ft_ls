/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 11:10:40 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/18 16:55:13 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		*get_mode_ex_ex(mode_t st_mode, char *r, int i)
{
	if (st_mode & S_ISVTX && st_mode & S_IXOTH)
		r[i++] = 't';
	else if (st_mode & S_ISVTX && !(st_mode & S_IXOTH))
		r[i++] = 'T';
	else if (st_mode & S_IXOTH)
		r[i++] = 'x';
	else
		r[i++] = '-';
	return (r);
}

static char		*get_mode_ex(mode_t st_mode, char *r, int i)
{
	if (st_mode & S_ISUID && st_mode & S_IXUSR)
		r[i++] = 's';
	else if (st_mode & S_ISUID && !(st_mode & S_IXUSR))
		r[i++] = 'S';
	else if (st_mode & S_IXUSR)
		r[i++] = 'x';
	else
		r[i++] = '-';
	r[i++] = (st_mode & S_IRGRP) ? 'r' : '-';
	r[i++] = (st_mode & S_IWGRP) ? 'w' : '-';
	if (st_mode & S_ISGID && st_mode & S_IXGRP)
		r[i++] = 's';
	else if (st_mode & S_ISGID && !(st_mode & S_IXGRP))
		r[i++] = 'S';
	else if (st_mode & S_IXGRP)
		r[i++] = 'x';
	else
		r[i++] = '-';
	r[i++] = (st_mode & S_IROTH) ? 'r' : '-';
	r[i++] = (st_mode & S_IWOTH) ? 'w' : '-';
	return (get_mode_ex_ex(st_mode, r, i));
}

static char		get_attr(char *pathname)
{
	acl_t	acl;

	if ((acl = acl_get_file(pathname, ACL_TYPE_EXTENDED)))
	{
		return ('+');
		acl_free((void *)acl);
	}
	else if ((listxattr(pathname, NULL, 0, XATTR_NOFOLLOW)) > 0)
		return ('@');
	return (' ');
}

char			*get_mode(mode_t st_mode, char *pathname)
{
	char	*r;
	int		i;

	i = 0;
	r = (char*)ft_memalloc(sizeof(char) * 12 + 1);
	r[10] = get_attr(pathname);
	r[11] = ' ';
	if (S_ISBLK(st_mode))
		r[i++] = 'b';
	else if (S_ISCHR(st_mode))
		r[i++] = 'c';
	else if (S_ISDIR(st_mode))
		r[i++] = 'd';
	else if (S_ISLNK(st_mode))
		r[i++] = 'l';
	else if (S_ISSOCK(st_mode))
		r[i++] = 's';
	else if (S_ISFIFO(st_mode))
		r[i++] = 'p';
	else if (S_ISREG(st_mode))
		r[i++] = '-';
	r[i++] = (st_mode & S_IRUSR) ? 'r' : '-';
	r[i++] = (st_mode & S_IWUSR) ? 'w' : '-';
	return (get_mode_ex(st_mode, r, i));
}
