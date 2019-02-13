# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/12 17:21:14 by julesqvgn         #+#    #+#              #
#    Updated: 2019/02/13 17:58:28 by jquivogn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = jquivogn.filler

LIBFT = -L ./Libft/ -I ./Libft/include -lft

LIBFTOBJ = -I ./Libft/include

INCLUDE = -I ./include/

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

all: logo libft $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(INCLUDE) $(OBJ) $(LIBFT) -o $(NAME) 2> /dev/null || true
	@echo "\033[38;2;0;255;255mfiller\t\033[1;33mCompilation\t\t\033[0;32m[OK]\033[0m"
	@echo "\033[38;2;0;255;255mfiller\t\033[38;2;255;0;0m$(NAME)\t\t\033[0;32m[OK]\033[0m"

libft:
	@$(MAKE) -C libft/

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH)
	@$(CC) $(FLAGS) $(INCLUDE) $(LIBFTOBJ) -c $< -o $@ 2> /dev/null || true

clean:
	@$(MAKE) -C libft/ clean
	@rm -rf $(OBJ)
	@echo "\033[38;2;0;255;255mfiller\t\033[1;33mCleaning obj\t\t\033[0;32m[OK]\033[0m"

fclean: clean
	@$(MAKE) -C libft/ fclean
	@rm -rf ./obj $(NAME)
	@echo "\033[38;2;0;255;255mfiller\t\033[1;33mCleaning exe\t\t\033[0;32m[OK]\033[0m"

logo:
	@echo "\033[38;2;255;128;0m"
	@echo "                   :::                                                                        ::: "
	@echo "                 :+:                                                                          :+: "
	@echo "               +:+  +:+:+:+:+:+:+ +:+:+:+:+:+:+ +:+:+:+:+:+:+ +:+:+:+:+:+:+ +:+:+:+:+:+:+     +:+ "
	@echo "             +#+                                                                              +#+ "
	@echo "           +#+    +#+#+#+#+#+#+ +#+#+#+#+#+#+ +#+#+#+#+#+#+ +#+#+#+#+#+#+ +#+#+#+#+#+#+       +#+ "
	@echo "         #+#                                                                                  #+# "
	@echo "       ###                                                                                    ### "
	@echo ""
	@echo "      :::  \033[38;2;255;0;128m        :::::::::: ::::::::::: :::        :::        :::::::::: :::::::::     \033[38;2;255;128;0m     ::: "
	@echo "     :+:   \033[38;2;255;0;128m       :+:            :+:     :+:        :+:        :+:        :+:    :+:     \033[38;2;255;128;0m    :+:  "
	@echo "    +:+    \033[38;2;255;0;128m      +:+            +:+     +:+        +:+        +:+        +:+    +:+       \033[38;2;255;128;0m  +:+   "
	@echo "           \033[38;2;255;0;128m     :#::+::#       +#+     +#+        +#+        +#++:++#   +#++:++#:         \033[38;2;255;128;0m        "
	@echo "  +#+      \033[38;2;255;0;128m    +#+            +#+     +#+        +#+        +#+        +#+    +#+        \033[38;2;255;128;0m +#+     "
	@echo " #+#       \033[38;2;255;0;128m   #+#            #+#     #+#        #+#        #+#        #+#    #+#        \033[38;2;255;128;0m #+#      "
	@echo "###        \033[38;2;255;0;128m  ###        ########### ########## ########## ########## ###    ###        \033[38;2;255;128;0m ###       "
	@echo ""
	@echo ":::                                                                                 ::: "
	@echo ":+:                                                                               :+:   "
	@echo "+:+    +:+:+:+:+:+:+ +:+:+:+:+:+:+ +:+:+:+:+:+:+ +:+:+:+:+:+:+ +:+:+:+:+:+:+    +:+     "
	@echo "+#+                                                                           +#+       "
	@echo "+#+  +#+#+#+#+#+#+ +#+#+#+#+#+#+ +#+#+#+#+#+#+ +#+#+#+#+#+#+ +#+#+#+#+#+#+  +#+         "
	@echo "#+#                                                                       #+#           "
	@echo "###                                                                     ### "
	@echo "\033[0m"

re: fclean all

.PHONY: all clean fclean re logo libft