/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ids.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 15:47:19 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/11 15:51:43 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_user(uid_t id)
{
	struct passwd 	*user;

	user = getpwuid(id);
	ft_putstr(user->pw_name);
}

void	print_group(gid_t id)
{
	struct group 	*grp;

	grp = getgrgid(id);
	ft_putstr(grp->gr_name);
}
