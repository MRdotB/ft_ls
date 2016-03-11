/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 15:34:39 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/11 15:53:34 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_mode_ex(mode_t st_mode)
{
	ft_putchar((st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((st_mode & S_IWGRP) ? 'w' : '-');
	if (st_mode & S_ISGID && st_mode & S_IXGRP)
		ft_putchar('s');
	else if (st_mode & S_ISGID && !(st_mode & S_IXGRP))
		ft_putchar('S');
	else if (st_mode & S_IXGRP)
		ft_putchar('x');
	else
		ft_putchar('-');
	ft_putchar((st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((st_mode & S_IWOTH) ? 'w' : '-');
	if (st_mode & S_ISVTX && st_mode & S_IXOTH)
		ft_putchar('t');
	else if (st_mode & S_ISVTX && !(st_mode & S_IXOTH))
		ft_putchar('T');
	else if (st_mode & S_IXOTH)
		ft_putchar('x');
	else
		ft_putchar('-');
}

void		print_mode(mode_t st_mode)
{
	if (S_ISBLK(st_mode))
		ft_putchar('b');
	else if (S_ISCHR(st_mode))
		ft_putchar('c');
	else if (S_ISDIR(st_mode))
		ft_putchar('d');
	else if (S_ISREG(st_mode))
		ft_putchar('-');
	else if (S_ISBLK(st_mode))
		ft_putchar('b');
	else if (S_ISSOCK(st_mode))
		ft_putchar('s');
	ft_putchar((st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((st_mode & S_IWUSR) ? 'w' : '-');
	if (st_mode & S_ISUID && st_mode & S_IXUSR)
		ft_putchar('s');
	else if (st_mode & S_ISUID && !(st_mode & S_IXUSR))
		ft_putchar('S');
	else if (st_mode & S_IXUSR)
		ft_putchar('x');
	else
		ft_putchar('-');
	print_mode_ex(st_mode);
}
