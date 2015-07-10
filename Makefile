# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/10 12:21:12 by aratinau          #+#    #+#              #
#    Updated: 2015/07/10 12:22:06 by aratinau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf

SRC = wolf.c

#ARGS = ../../42_projects/fdf/new_start/maps

OBJ_PATH = ./obj/

OBJ2 = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra
OBJ = $(addprefix $(OBJ_PATH),$(OBJ2))

#ecole
$(NAME): $(OBJ)
	make -C ../libraire/
	$(CC) $(CFLAGS) ../libraire/libft.a -o $(NAME) $(OBJ) \
	-lmlx -framework OpenGL -framework AppKit

#maison
#$(NAME): $(OBJ)
#	make -C ../libraire/
#	make -C ../../minilibx_test_ok/includes/minilibx/
#	$(CC) $(CFLAGS) ../libraire/libft.a \
	../../minilibx_test_ok/includes/minilibx/libmlx.a -o $(NAME) $(OBJ) \
	-lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(OBJ_PATH)%.o: %.c
	@mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

#run: ${NAME}
#	./${NAME}
