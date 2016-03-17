/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:34:40 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/17 15:39:34 by bchaleil         ###   ########.fr       */
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

# define LEFT 0
# define RIGHT 1

typedef struct			s_file
{
	char				*name;
	char				*path;
	struct stat			fs;
	struct s_file		*next;
}						t_file;

typedef struct			s_pad
{
	int					prepad;
	int					postpad;
	int					direction;
}						t_pad;

void		merge_sort(t_file** head_ref, int (*f)(t_file*, t_file*));
void		usage(char c);
void		ls_perror(char *str);
char		*get_mode(mode_t st_mode, char *pathname);
char		*get_user(uid_t id);
char		*get_group(gid_t id);
void		print_attr(char *pathname);
t_flag		options_check(int ac, char **av);
char		**files_check(int ac, char **av);
char		*get_path(char *arg);
t_file		*get_t_file_info(char *dir_name);
void 		printList(t_file *node);
int			order(t_file *a, t_file *b);
int			reverse(t_file *a, t_file *b);
void		format_file(t_file *f, t_flag flag);
int			*max_padding(t_file *f, t_flag flag);
char		*padding_str(char *str, int size, t_pad p);
t_pad		ret_pad(int prepad, int postpad, int direction);

# endif
