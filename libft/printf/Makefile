# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joafaust <joafaust@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 15:35:41 by joafaust          #+#    #+#              #
#    Updated: 2024/05/07 15:53:36 by joafaust         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC =  	ft_printf.c

CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
OBJS = $(SRC:.c=.o)
all:$(NAME)

$(NAME): $(OBJS)
			ar rc $(NAME) $(OBJS)
clean:
	$(RM)	$(OBJS)
fclean: clean
		$(RM)	$(NAME)
re:	fclean	$(NAME)