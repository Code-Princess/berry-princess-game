# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 12:27:10 by llacsivy          #+#    #+#              #
#    Updated: 2024/05/24 18:42:02 by llacsivy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= so_long
CFLAGS		:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBDOTA		:= ./MLX42/build/libmlx42.a

LIBMLX42	:= ./MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm
MLX42_URL	= https://github.com/codam-coding-college/MLX42.git

INCL		:=	-I ./MLX42/include
SRCS		:= main.c
OBJS		:=	${SRCS:.c=.o}

%.o: %.c
	cc $(CFLAGS) -c $< -o $@ $(INCL)

all: $(LIBDOTA) $(NAME)

$(LIBDOTA):
	@echo "Making MLX42..."
	git clone $(MLX42_URL)
	cmake ./MLX42 -B ./MLX42/build && make -C ./MLX42/build -j4

$(NAME): $(LIBDOTA) $(OBJS)
	@echo "Compiling so_long ..."
	cc $(OBJS) $(LIBMLX42) $(INC) -o $(NAME)

clean:
	@echo "Cleaning object files..."
	rm -f $(OBJS)
	rm -rf ./MLX42/build
	rm -rf ./MLX42

fclean : clean
	@echo "Cleaning so_long"
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
