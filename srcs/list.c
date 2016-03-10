/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 14:44:06 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/10 15:31:38 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_list_dir(char *dir_name)
{
	struct dirent	*p_dirent;
	DIR				*p_dir;

	p_dir = opendir(dir_name);
	if (p_dir == NULL)
		return perror(NULL);
	while ((p_dirent = readdir(p_dir)) != NULL)
		ft_putendl(p_dirent->d_name);
	closedir(p_dir);
}

int main(char **av)
{
    if (ac != 2)    
        return (1);
    struct stat file_stat;
    if (stat(av[1], &file_stat) < 0)    
        return (1);
	ft_putstr("Information")
	ft_putndl(argv[1]);
    ft_putndl("---------------------------");
	ft_putstr("User id of the file")
	ft_putnbdrnl(file_stat.st_uid);
    printf("User Id of the file: %d\n", fileStat.st_uid);
    printf("Group Id of the file: %d\n", fileStat.st_gid);
    printf("Device Id: %d\n", fileStat.st_rdev);
    printf("File Size: \t\t%lld bytes\n", fileStat.st_size);
    printf("Number of Links: \t%d\n", fileStat.st_nlink);
    printf("File inode: \t\t%lld\n", fileStat.st_ino);
    printf("File Permissions: \t");
    printf( (S_ISDIR(file_stat.st_mode)) ? "d" : "-");
	print_file_mode(file_stat.st_mode);
    printf("\n\n");
 
    printf("The file %s a symbolic link\n", (S_ISLNK(fileStat.st_mode)) ? "is" : "is not");
    return 0;
}
