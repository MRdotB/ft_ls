/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:18:58 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/11 19:21:46 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int ac, char **av)
{
	int				i;
	struct stat		file_stat;
	char			*linkname;
	ssize_t			r;

	i = 0;
	while (++i < ac)
		list_dir(av[i]);
	if (lstat(av[1], &file_stat) < 0)    
        return (1);

	ft_putstr("\n\n");
	print_mode(file_stat.st_mode);
	print_attr(av[1]);
	ft_putstr("  ");
    ft_putnbr(file_stat.st_nlink);
	ft_putstr("  ");
	print_user(file_stat.st_uid);
	ft_putstr("  ");
	print_group(file_stat.st_gid);
	ft_putstr("  ");
	ft_putnbrll(file_stat.st_size);
	ft_putstr(ctime(&file_stat.st_mtimespec.tv_sec));
	ft_putstr("  ");
	ft_putstr(av[1]);
	if (S_ISLNK(file_stat.st_mode))
	{
		linkname = ft_strnew(file_stat.st_size);
		r = readlink(av[1], linkname, file_stat.st_size + 1);
		if (r == -1)
		{
			perror("readlink");
			exit(EXIT_FAILURE);
		}
		ft_putstr("->");
		ft_putendl(linkname);
		ft_memdel((void**)&linkname);
	}

    printf("File Size: \t\t%lld bytes\n", file_stat.st_size);
	//Used to count the total
	//Count the invisible file only if the a option is provided
    printf("File Size: \t\t%lld bytes\n", file_stat.st_blocks);
	return (0);
}
