# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/24 13:57:10 by aeclipso          #+#    #+#              #
#    Updated: 2020/11/07 17:10:18 by aeclipso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf

FLAGS=-Wall -Werror -Wextra  -O3 -ffast-math -g
LIBRARIES = -lmlx  -lm -lft -L$(LIBFT_D) -L$(MINILIBX_D) -framework OpenGL -framework AppKit

INCLUDES+= -I include
INCLUDES+= -I $(LIBFT_D)/include
INCLUDES+= -I ./minilibx/

LIBFT_D=libft-printf
LIBFT = $(LIBFT_D)/libft.a 

MINILIBX_D=minilibx
MINILIBX = $(MINILIBX_D)libmlx.a 

SRC=main.c\
	init_map.c

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX)
	# @gcc -g -o $@ $^ -L $(LIBFT_D) -lft
	@gcc $(FLAGS) $(INCLUDES) -c $(SRC)
	@gcc $(FLAGS) -g $(LIBRARIES) $(INCLUDES) -o $(NAME) $(OBJ)

libft.a :
	@$(MAKE) --no-print-directory -C $(LIBFT_D) all

$(MINILIBX):
	@$(MAKE) -sC $(MINILIBX_D)

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