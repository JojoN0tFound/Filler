# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julesqvgn <julesqvgn@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/12 17:21:14 by julesqvgn         #+#    #+#              #
#    Updated: 2019/02/12 17:58:04 by julesqvgn        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PHONY: all clean fclean re norme

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = jquivogn.filler

LIBFT = -lft -L./libft/ -I./libft/include

INCLUDE = -I./include/

SRC_PATH = ./src
INC_PATH = ./include/
OBJ_PATH = ./obj

SRC_NAME =	main.c \

INC_NAME = filler.h
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJLIB_NAME = $(LIB_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ) filler.h
	@$(MAKE) -C libft/
	@$(CC) $(FLAGS) $(INCLUDE) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "\033[1;34mfiller\t\033[1;33mCompilation exe\t\033[0;32m[OK]\033[0m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) $(INCLUDE) $< -o $@

clean:
	@$(MAKE) -C libft/ clean
	@rm -rf $(OBJ)
	@echo "\033[1;34mfiller\t\033[1;33mCleaning obj\t\033[0;32m[OK]\033[0m"

fclean: clean
	@$(MAKE) -C libft/ fclean
	@rm -rf ./obj $(NAME)
	@echo "\033[1;34mfiller\t\033[1;33mCleaning exe\t\033[0;32m[OK]\033[0m"

re: fclean all