# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: linda <linda@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 12:27:10 by llacsivy          #+#    #+#              #
#    Updated: 2024/06/11 11:24:25 by linda            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= so_long
CFLAGS		:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLXDOTA	:= ./MLX42/build/libmlx42.a

LIBMLX42	:= ./MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm
MLX42_URL	= https://github.com/codam-coding-college/MLX42.git
INCL		:=	-I ./MLX42/include

LIBFTDOTA	:=	libft/libft.a
SRCS		:=	so_long.c ./so_long_utils/map_checks.c ./so_long_utils/map_helper_functions.c \
				./so_long_utils/components_checks.c ./so_long_utils/valid_path_checks.c ./so_long_utils/game_init_functions.c \
				./so_long_utils/game_textures_functions.c ./so_long_utils/hook_fuctions.c
				
OBJS		:=	${SRCS:.c=.o}
OBJS_DEBUG		:=	${SRCS:.c=_debug.o}

$(NAME): $(LIBMLXDOTA) $(LIBFTDOTA) $(OBJS)
	@echo "Compiling so_long ..."
	cc $(OBJS) $(LIBMLX42) $(LIBFTDOTA) $(INC) -o $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@ $(INCL)
%_debug.o: %.c
	cc $(CFLAGS) -g -c $< -o $@ $(INCL)

all: $(LIBMLXDOTA) $(NAME)
debug: $(LIBMLXDOTA) so_long_debug


so_long_debug: $(LIBMLXDOTA) libft/libft_debug.a $(OBJS_DEBUG)
	@echo "Compiling so_long_DEBUG ..."
	cc -g $(OBJS_DEBUG) $(LIBMLX42) libft/libft_debug.a $(INC) -o so_long_debug

$(LIBMLXDOTA):
	@echo "Making MLX42..."
	git clone $(MLX42_URL)
	cmake ./MLX42 -B ./MLX42/build && make -C ./MLX42/build -j4

$(LIBFTDOTA):
	$(MAKE) -C libft/

libft/libft_debug.a:
	$(MAKE) -C libft/ libft_debug.a

clean:
	@echo "Cleaning object files..."
	$(MAKE) clean -C libft/
	rm -f $(OBJS) $(OBJS_DEBUG)
	rm -rf ./MLX42/build
	rm -rf ./MLX42

fclean : clean
	@echo "Cleaning so_long"
	$(MAKE) fclean -C libft/
	
	rm -f $(NAME) so_long_debug

re: fclean all

.PHONY: all clean fclean re debug
