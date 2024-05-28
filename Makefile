# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 12:27:10 by llacsivy          #+#    #+#              #
#    Updated: 2024/05/28 20:08:50 by llacsivy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= so_long
CFLAGS		:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLXDOTA	:= ./MLX42/build/libmlx42.a

LIBMLX42	:= ./MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm
MLX42_URL	= https://github.com/codam-coding-college/MLX42.git
INCL		:=	-I ./MLX42/include

LIBFTDOTA	:=	libft/libft.a
SRCS		:=	so_long.c ./so_long_utils/map_checks.c ./so_long_utils/map_checks_utils.c
OBJS		:=	${SRCS:.c=.o}

$(NAME): $(LIBMLXDOTA) $(LIBFTDOTA) $(OBJS)
	@echo "Compiling so_long ..."
	cc $(OBJS) $(LIBMLX42) $(LIBFTDOTA) $(INC) -o $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@ $(INCL)

all: $(LIBMLXDOTA) $(NAME)

$(LIBMLXDOTA):
	@echo "Making MLX42..."
	git clone $(MLX42_URL)
	cmake ./MLX42 -B ./MLX42/build && make -C ./MLX42/build -j4

$(LIBFTDOTA):
	$(MAKE) -C libft/


clean:
	@echo "Cleaning object files..."
	$(MAKE) clean -C libft/
	rm -f $(OBJS)
	rm -rf ./MLX42/build
	rm -rf ./MLX42

fclean : clean
	@echo "Cleaning so_long"
	$(MAKE) fclean -C libft/
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
