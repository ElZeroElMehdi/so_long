# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/26 17:20:51 by eelmoham          #+#    #+#              #
#    Updated: 2022/03/16 01:38:34 by eelmoham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS  = ./mandatory/so_long.c \
		./mandatory/ft_split.c \
		./mandatory/func.c \
		./mandatory/ft_putnbr.c \
		./mandatory/map_errors.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c

header =./mandatory/so_long.h

OBJ = $(SRCS:.c=.o)

FLAGS =gcc -Wall -Wextra -Werror 

LMLX = -lmlx -framework OpenGL -framework AppKit

$(NAME): $(OBJ) $(header)
	$(FLAGS) $(OBJ) $(LMLX) -o $(NAME)

clean :
	rm -f $(OBJ)
fclean : clean
	rm -f so_long

re : fclean $(NAME)

.PHONY: clean fclean re