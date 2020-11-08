# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/24 13:57:10 by aeclipso          #+#    #+#              #
#    Updated: 2020/11/08 16:19:30 by aeclipso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf

FLAGS=-Wall -Werror -Wextra  -O3 -ffast-math
LIBRARIES = -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -L$(LIBFT_D)


INCLUDES+= -I include
INCLUDES+= -I $(LIBFT_D)/include
# INCLUDES+= -I ./minilibx/

LIBFT_D=libft-printf
LIBFT = $(LIBFT_D)/libft.a 

MINILIBX_D=minilibx
MINILIBX = $(MINILIBX_D)libmlx.a 

SRC=main.c\
	init_map.c\
	hooks.c\
	render.c\
	render_tools.c

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT)
	@gcc $(FLAGS) $(INCLUDES) $(LIBRARIES) $(SRC) $(LIBFT) -o fdf
	# @gcc $(FLAGS) -g $(LIBRARIES) $(INCLUDES) -o $(NAME) $(OBJ)

libft.a :
	@$(MAKE) --no-print-directory -C $(LIBFT_D) all

# $(MINILIBX):
# 	@$(MAKE) -sC $(MINILIBX_D)

# $(OBJ): %.o: %.c
# 		@gcc -g $(FLAGS) $(INCLUDES) -MD -o $@ -c $<

# clean:
# 	@rm -f $(OBJ)
# 	@$(MAKE) --no-print-directory -C $(LIBFT_D) clean

# fclean: clean
# 	@rm -f $(NAME)
# 	@rm -f $(FOLDER)$(NAME)
# 	# @$(MAKE) --no-print-directory -C $(LIBFT_D) fclean

# re: fclean all

clean:
	@$(MAKE) -sC $(LIBFT_D) clean
	@$(MAKE) -sC $(MINILIBX_D) clean
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(LIBFT)
	@rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all