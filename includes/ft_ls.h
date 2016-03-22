/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:34:40 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/22 16:35:01 by bchaleil         ###   ########.fr       */
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
# define F_COLO 32
# define F_PATH 64
# define F_ERRO 1073741824

# define LEFT 0
# define RIGHT 1

# define SIXMONTH 15778458

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

void					merge_sort(t_file **head_ref,
		int (*f)(t_file*, t_file*));
void					recursive_reverse(t_file **head_ref);
int						order(t_file *a, t_file *b);

void					usage(char c);
void					ls_perror(char *str);

char					*get_min_maj(dev_t	rdev);
char					*get_mode(mode_t st_mode, char *pathname);
char					*get_user(uid_t id);
char					*get_group(gid_t id);
t_string				*get_date(struct timespec t);
char					*get_path(char *arg);
t_file					*get_t_file_info(char *dir_name);
char					*get_color(mode_t st_mode);
void					format_file(t_file *f, t_flag flag);
t_pad					ret_pad(int prepad, int postpad, int direction);
char					*padding_str(char *str, int size, t_pad p);
int						bytime(t_file *a, t_file *b);

t_flag					options_check(int ac, char **av);
char					**files_check(int ac, char **av);

void					max_padding(int padding[], t_file *f, t_flag flag);

#endif
