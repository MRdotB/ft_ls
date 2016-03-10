/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:18:58 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/10 20:52:14 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int ac, char **av)
{
	int				i;
	struct stat		file_stat;
	struct passwd 	*user;
	struct group 	*grp;

	i = 0;
	while (++i < ac)
		list_dir(av[i]);
	if (lstat(av[1], &file_stat) < 0)    
        return (1);

	ft_putstr("\n\n");
	print_file_mode(file_stat.st_mode);
	ft_putstr("  ");
    ft_putnbr(file_stat.st_nlink);
	ft_putstr("  ");
	user = getpwuid(file_stat.st_uid);
	ft_putstr(user->pw_name);
	ft_putstr("  ");
	grp = getgrgid(file_stat.st_gid);
	ft_putstr(grp->gr_name);
	ft_putstr("  ");
	ft_putnbrll(file_stat.st_size);
	ft_putstr(ctime(&file_stat.st_mtimespec.tv_sec));
	ft_putstr("  ");
	ft_putendl(av[1]);
	if (S_ISLNK(file_stat.st_mode))
	{
			printf("this is a link\n");
	}
	if (S_ISREG(file_stat.st_mode))
			printf("this is not a link\n");

    printf("File Size: \t\t%lld bytes\n", file_stat.st_size);
	//Used to count the total
	//Count the invisible file only if the a option is provided
    printf("File Size: \t\t%lld bytes\n", file_stat.st_blocks);
	/*

	ft_putstr("Information");
	ft_putendl(av[1]);
    ft_putendl("---------------------------");
	ft_putstr("User id of the file");
	//User Id of the file
	ft_putnbrnl(file_stat.st_uid);
	//Group Id of the file
	ft_putnbrnl(file_stat.st_gid);
	//Device Id
	ft_putnbrnl(file_stat.st_rdev);
	//File stat
    printf("File Size: \t\t%lld bytes\n", file_stat.st_size);
	//file inode
    printf("File inode: \t\t%lld\n", file_stat.st_ino);
	//file mode;
    printf("\n\n");

	*/
	return (0);
}
