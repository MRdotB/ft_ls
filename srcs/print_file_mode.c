/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_mode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:19:27 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/10 21:00:37 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_file_mode(mode_t st_mode)
{
	if (S_ISBLK(st_mode))
		ft_putchar('b');
	if (S_ISCHR(st_mode))
		ft_putchar('c');
	if (S_ISDIR(st_mode))
		ft_putchar('d');
	if (S_ISREG(st_mode))
		ft_putchar('-');
	if (S_ISBLK(st_mode))
		ft_putchar('b');
	if (S_ISSOCK(st_mode))
		ft_putchar('s');
    ft_putchar((st_mode & S_IRUSR) ? 'r' : '-');
    ft_putchar((st_mode & S_IWUSR) ? 'w' : '-');
    ft_putchar((st_mode & S_IXUSR) ? 'x' : '-');
    ft_putchar((st_mode & S_IRGRP) ? 'r' : '-');
    ft_putchar((st_mode & S_IWGRP) ? 'w' : '-');
    ft_putchar((st_mode & S_IXGRP) ? 'x' : '-');
    ft_putchar((st_mode & S_IROTH) ? 'r' : '-');
    ft_putchar((st_mode & S_IWOTH) ? 'w' : '-');
    ft_putchar((st_mode & S_IXOTH) ? 'x' : '-');
	//t T sticky bit
	//@ attribut
}
