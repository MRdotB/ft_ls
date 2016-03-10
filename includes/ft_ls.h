/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:34:40 by bchaleil          #+#    #+#             */
/*   Updated: 2016/03/10 15:58:57 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft.h"

# include <stdio.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <time.h>
#include <grp.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <errno.h>

# define NO_FLAGS 0
# define LIST_FLAG 1
# define RECURSE_FLAG 2
# define ADOT_FLAG 4
# define REVERSE_FLAG 8
# define TIME_FLAG 16

void	usage(char c);
void	ls_perror(char *str);
void	list_dir(char *dir_name);
void	print_file_mode(mode_t st_mode);

#endif
