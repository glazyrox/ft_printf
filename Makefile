# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/22 16:20:25 by rgwayne-          #+#    #+#              #
#    Updated: 2019/11/26 21:26:58 by rgwayne-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC = 	ft_printf.c \
		ft_only_one_arg.c

all: $(NAME)

$(NAME):
	gcc -g $(FLAGS) -c $(SRC)
	ar -rc $(NAME) *.o

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all