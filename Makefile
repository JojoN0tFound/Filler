# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/12 17:21:14 by julesqvgn         #+#    #+#              #
#    Updated: 2019/03/02 23:28:16 by jquivogn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

NAME = jquivogn.filler

VIZU_BIN = filler.vizu

LIBFT = -L ./Libft/ -I ./Libft/include -lft

LIBFTOBJ = -I ./Libft/include

INCLUDE = -I ./include/

MLX = -lmlx -framework OpenGL -framework AppKit

SRC_PATH = ./src
INC_PATH = ./include
OBJ_PATH = ./obj

SRC_NAME =	main.c \
			play.c \
			get.c \
			utils.c

VIZU_NAME =	vizu/mainvizu.c \
			vizu/print.c \
			vizu/tools.c \
			vizu/use.c \
			vizu/read.c

INC_NAME =	vizu.h \
			filler.h

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_VIZU_NAME = $(VIZU_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
VIZU = $(addprefix $(VIZU_PATH)/, $(VIZU_NAME))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
OBJ_VIZU = $(addprefix $(OBJ_PATH)/,$(OBJ_VIZU_NAME))

all: logo libft $(NAME) $(VIZU_BIN)

exe: logo libft $(NAME)

vizu: logo libft $(VIZU_BIN)

libft:
	@$(MAKE) -C libft/

$(NAME): $(OBJ) $(INC)
	@$(CC) $(FLAGS) $(INCLUDE) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "\033[38;2;0;255;255mfiller\t\033[1;33mCompilation\t\t\033[0;32m[OK]\033[0m"
	@echo "\033[38;2;0;255;255mfiller\t\033[38;2;255;0;0m$(NAME)\t\t\033[0;32m[OK]\033[0m"

$(VIZU_BIN): $(OBJ) $(OBJ_VIZU) $(INC)
	@$(CC) $(FLAGS) $(INCLUDE) $(OBJ_VIZU) $(MLX) $(LIBFT) -o $(VIZU_BIN)
	@echo "\033[38;2;0;200;255mvizu\t\033[1;33mCompilation\t\t\033[0;32m[OK]\033[0m"
	@echo "\033[38;2;0;200;255mvizu\t\033[38;2;255;0;0m$(VIZU_BIN)\t\t\033[0;32m[OK]\033[0m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(dir $(OBJ_PATH)/$*) 2> /dev/null || true
	@echo "\033[38;2;0;255;0m[cc]\033[0m: $< -> $@"
	@printf "\e[1A"
	@$(CC) $(FLAGS) $(INCLUDE) $(LIBFTOBJ) -c $< -o $@
	@printf "\e[0K"

clean:
	@$(MAKE) -C libft/ clean
	@rm -rf $(OBJ) $(OBJ_VIZU) $(OBJ_PATH)
	@echo "\033[38;2;0;255;255mfiller\t\033[1;33mCleaning obj\t\t\033[0;32m[OK]\033[0m"
	@echo "\033[38;2;0;200;255mvizu\t\033[1;33mCleaning obj\t\t\033[0;32m[OK]\033[0m"

fclean: clean
	@$(MAKE) -C libft/ fclean
	@rm -rf $(NAME) $(VIZU_BIN)
	@echo "\033[38;2;0;255;255mfiller\t\033[1;33mCleaning exe\t\t\033[0;32m[OK]\033[0m"
	@echo "\033[38;2;0;200;255mvizu\t\033[1;33mCleaning exe\t\t\033[0;32m[OK]\033[0m"

logo:
	@echo ""
	@echo  "\033[38;2;255;128;0m:::::::::: ::::::::::: :::        :::        :::::::::: :::::::::  "
	@echo "\033[38;2;255;105;21m:+:            :+:     :+:        :+:        :+:        :+:    :+: "
	@echo  "\033[38;2;255;84;42m+:+            +:+     +:+        +:+        +:+        +:+    +:+ "
	@echo  "\033[38;2;255;63;63m:#::+::#       +#+     +#+        +#+        +#++:++#   +#++:++#:  "
	@echo  "\033[38;2;255;42;84m+#+            +#+     +#+        +#+        +#+        +#+    +#+ "
	@echo "\033[38;2;255;21;105m#+#            #+#     #+#        #+#        #+#        #+#    #+# "
	@echo  "\033[38;2;255;0;128m###        ########### ########## ########## ########## ###    ### "
	@echo "\033[0m    \033[38;2;0;255;191m"

re: fclean all

.PHONY: all vizu clean fclean re logo libft
