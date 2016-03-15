/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:34:40 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/15 18:30:37 by bchaleil         ###   ########.fr       */
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
# include <limits.h>

typedef int		t_flag;
# define F_NULL 0
# define F_LIST 1
# define F_RECS 2
# define F_ADOT 4
# define F_REVS 8
# define F_TIME 16
# define F_ERRO 1073741824


typedef struct			s_file
{
	char				*name;
	char				*path;
	struct stat			fs;
	struct s_file		*next;
}						t_file;

void		usage(char c);
void		ls_perror(char *str);
void		print_mode(mode_t st_mode);
void		print_user(uid_t id);
void		print_group(gid_t id);
void		print_attr(char *pathname);
t_flag		argv_check(int ac, char **av);
char		*get_path(char *arg);
t_file		*list_file_info(char *dir_name);

#endif
