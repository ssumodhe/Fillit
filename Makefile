# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/12 14:37:10 by ssumodhe          #+#    #+#              #
#    Updated: 2017/01/13 17:17:01 by ssumodhe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra

NAME = fillit

SRCS = fillit_main.c \
	   fillit_algo1.c \
	   fillit_algo2.c \
	   fillit_check.c \
	   fillit_lst.c  

OBJECT = $(SRCS:.c=.o)

INCL_LIB = libft/
LIB = libft/libft.a

all: $(NAME) 

$(LIB):
	make -C $(INCL_LIB)
	@echo "\033[1;32mlibft.a DONE\033[0m"

$(NAME): $(LIB) $(OBJECT)
	@gcc $(FLAGS) $(LIB) $(OBJECT) -I $(INCL_LIB) -o $(NAME) 
	@echo "\033[1;32mfillit DONE\033[0m"

%.o: %.c
	@gcc $(FLAGS) -o $@ -c $< -I $(INCL_LIB) 
	@echo "\033[1;32m$@ DONE\033[0m"

clean:
	@make -C $(INCL_LIB) clean
	@rm -rf $(OBJECT)

fclean: clean
	@make -C $(INCL_LIB) fclean
	@rm -rf $(NAME)

re: fclean all
