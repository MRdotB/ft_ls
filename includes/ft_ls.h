/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:34:40 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/14 13:14:27 by bchaleil         ###   ########.fr       */
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

typedef int		t_flag;
# define F_NULL 0
# define F_LIST 1
# define F_RECS 2
# define F_ADOT 4
# define F_REVS 8
# define F_TIME 16
# define F_ERRO 1073741824

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
t_flag	argv_check(int ac, char **av);

#endif
