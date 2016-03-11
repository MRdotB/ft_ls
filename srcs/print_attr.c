/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_attr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 19:02:16 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/11 21:07:44 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_attr(char *pathname)
{
	acl_t	acl;

	if ((acl = acl_get_file(pathname, ACL_TYPE_EXTENDED)))
	{
		ft_putchar('+');
		acl_free((void *)acl);
	}
	if ((listxattr(pathname, NULL, 0, XATTR_NOFOLLOW)) > 0)
		ft_putchar('@');
}
