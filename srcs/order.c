/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:31:24 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/22 13:48:14 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		order(t_file *a, t_file *b)
{
	return (ft_strcmp(b->name, a->name) > 0);
}

int		bytime(t_file *a, t_file *b)
{
	return (b->fs.st_mtimespec.tv_sec < a->fs.st_mtimespec.tv_sec);
}

void	recursive_reverse(t_file **head_ref)
{
	t_file	*first;
	t_file	*rest;

	if (*head_ref == NULL)
		return ;
	first = *head_ref;
	rest = first->next;
	if (rest == NULL)
		return ;
	recursive_reverse(&rest);
	first->next->next = first;
	first->next = NULL;
	*head_ref = rest;
}
