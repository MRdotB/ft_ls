# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/12 16:21:36 by bchaleil          #+#    #+#              #
#    Updated: 2016/03/18 18:15:00 by bchaleil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	gcc
NAME			=	ft_ls
FLAGS			=	-Wall -Werror -Wextra -g
LIB_PATH		=	libft/
LIB				=	$(LIB_PATH)libft.a
LIB_LINK		=	-L $(LIB_PATH) -lft
INCLUDES		=	-I ./includes -I ./libft/includes
SRCS			=	srcs/main.c\
					srcs/errors.c\
					srcs/get_t_file_info.c\
					srcs/get_mode.c\
					srcs/get_min_maj.c\
					srcs/get_ids.c\
					srcs/options_check.c\
					srcs/files_check.c\
					srcs/get_path.c\
					srcs/merge_sort.c\
					srcs/format_file.c\
					srcs/padding.c\
					srcs/get_date.c\
					srcs/order.c
OBJS			=	$(SRCS:srcs/%.c=obj/%.o)

all: obj $(NAME)

$(NAME): $(LIB) $(OBJS)
	@echo "  __ _     _           "
	@echo " / _| |   | |          "
	@echo "| |_| |_  | |___   ___ "
	@echo "|  _| __| | / __| / __|"
	@echo "| | | |_  | \__ \| (__ "
	@echo "|_|  \__| |_|___(_)___|"
	@$(CC) $(FLAGS) -o $@ $^ $(LIB_LINK)

$(LIB):
	@make -C $(LIB_PATH)

obj:
	@mkdir -p obj

obj/%.o: srcs/%.c
	$(CC) $(FLAGS) $(INCLUDES) -c -o $@ $<

clean:
	@rm -f $(OBJS)
	@rm -rf obj

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean

re: fclean all

.PHONY:clean fclean re
