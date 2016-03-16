/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:18:58 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/16 21:42:07 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void printList(t_file *node)
{
	while (node != NULL)
	{
		ft_putendl(node->name);
		node = node->next;
	}
}

int	main(int ac, char **av)
{

	t_file	*f;
	t_flag	flag;
	char	**files;
//	char	*result;
	int		i;

	i = 0;
	flag = options_check(ac, av);
	//debug
	ft_putstr("flags: ");
	ft_print_binary(flag);
	ft_putstr("\n");
	files = files_check(ac, av); 
	while (files[i])
	{
		f = get_t_file_info(files[i]);
		merge_sort(&f, order);
		format_file(f, flag);
		ft_putendl(files[i]);
		i++;
	}
	return (0);
}
