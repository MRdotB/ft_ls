/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ids.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:31:27 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/22 17:03:49 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_user(uid_t id)
{
	struct passwd	*user;

	user = getpwuid(id);
	if (user)
		return (ft_strdup(user->pw_name));
	return (ft_itoa(id));
}

char	*get_group(gid_t id)
{
	struct group	*grp;

	grp = getgrgid(id);
	if (grp)
		return (ft_strdup(grp->gr_name));
	return (ft_itoa(id));
}
