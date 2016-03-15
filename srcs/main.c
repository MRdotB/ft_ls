/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:18:58 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/15 19:28:26 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int ac, char **av)
{

	t_file	*f;
	/*
	t_flag	flag;
	flag = argv_check(ac, av);
	//debug
	ft_putstr("flags: ");
	ft_print_binary(flag);
	ft_putstr("\n");
	*/
	if (ac == 1)
		return (0);
	f = list_file_info(av[1]);
	while (f)
	{
		ft_putstr("st mode ");
		print_mode(f->fs.st_mode);
		ft_putstr("\nf->name ");
		ft_putendl(f->name);
		ft_putstr("f->path ");
		ft_putendl(f->path);
		f = f->next;
	}
	return (0);
}
