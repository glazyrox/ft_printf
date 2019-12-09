# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/22 16:20:25 by rgwayne-          #+#    #+#              #
#    Updated: 2019/12/09 20:06:52 by rgwayne-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

# FLAGS = -Wall -Wextra -Werror

SRC = 	ft_printf.c \
		parser.c \
		converser.c \
		string_maker.c \
		word_width_maker.c \
		ft_new_itoa.c \
		test_lists.c \
		ft_flags.c \
		word_prec_maker.c \
		buffer.c \
		libft.c

all: $(NAME)

$(NAME):
	gcc -g $(FLAGS) -c $(SRC)
	ar -rc $(NAME) *.o

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all