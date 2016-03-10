/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:53:44 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/07 18:35:47 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	list_dir(char *dir_name)
{
	struct dirent	*p_dirent;
	DIR				*p_dir;

	p_dir = opendir(dir_name);
	if (p_dir == NULL)
	{
		return ls_perror(dir_name);
	}
	while ((p_dirent = readdir(p_dir)) != NULL)
		ft_putendl(p_dirent->d_name);
	closedir(p_dir);
}
