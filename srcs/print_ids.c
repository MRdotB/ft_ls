/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ids.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 15:47:19 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/14 17:56:22 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_user(uid_t id)
{
	struct passwd 	*user;

	user = getpwuid(id);
	if (user->pw_name)
		return (ft_putstr(user->pw_name));
	ft_putnbr(id);
}

void	print_group(gid_t id)
{
	struct group 	*grp;

	grp = getgrgid(id);
	if (grp->gr_name)
		return (ft_putstr(grp->gr_name));
	ft_putnbr(id);
}
