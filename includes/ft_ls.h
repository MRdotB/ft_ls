/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:34:40 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/11 19:22:08 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft.h"

# include <stdio.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <time.h>
# include <grp.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <errno.h>
# include <sys/acl.h>

# define NO_FLAGS 0
# define LIST_FLAG 1
# define RECURSE_FLAG 2
# define ADOT_FLAG 4
# define REVERSE_FLAG 8
# define TIME_FLAG 16

typedef struct		s_lformat
{
	mode_t			mode;
	char			attr;
	uid_t			uid;
	gid_t			gid;
	off_t			size;
	struct timespec	last_modif;
	blkcnt_t		blocks;
	char			*pathname;
	int				color;
	int				symlink_info;
	char			*linkname;
	dev_t			mkdev;
}					t_lformat;

void	usage(char c);
void	ls_perror(char *str);
void	list_dir(char *dir_name);
void	print_mode(mode_t st_mode);
void	print_user(uid_t id);
void	print_group(gid_t id);
void	print_attr(char *pathname);

#endif
