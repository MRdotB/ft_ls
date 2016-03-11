# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/12 16:21:36 by bchaleil          #+#    #+#              #
#    Updated: 2016/03/11 15:53:00 by bchaleil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	gcc
NAME			=	ft_ls
FLAGS			=	-Wall -Werror -Wextra
LIB_PATH		=	libft/
LIB				=	$(LIB_PATH)libft.a
LIB_LINK		=	-L $(LIB_PATH) -lft
INCLUDES		=	-I ./includes -I ./libft/includes
SRCS			=	srcs/main.c\
					srcs/errors.c\
					srcs/list_dir.c\
					srcs/print_mode.c\
					srcs/print_attr.c\
					srcs/print_ids.c
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
	@$(CC) $(FLAGS) $(INCLUDES) -c -o $@ $<

clean:
	@rm -f $(OBJS)
	@rm -rf obj

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean

re: fclean all

.PHONY:clean fclean re
