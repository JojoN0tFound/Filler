 # **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/11 22:26:09 by nivergne          #+#    #+#              #
#    Updated: 2019/02/12 03:05:59 by jquivogn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re norme

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = libft.a

INCLUDE = -I./include/

SRC_PATH = ./ft_printf
LIB_PATH = ./src_libft
INC_PATH = ./include/
OBJ_PATH = ./obj
OBJLIB_PATH = ./obj

SRC_PRINTF =	./else.c \
				./print_per.c \
				./print_b.c \
				./print_c.c \
				./print_s.c \
				./print_p.c \
				./print_i.c \
				./print_o.c \
				./print_u.c \
				./print_x.c \
				./print_f.c \
				./print_ff.c \
				./width_csp.c \
				./width_dioux.c \
				./convert_base.c \
				./parse.c \
				./ft_printf.c

LIB_NAME =		./ft_atoi.c \
				./ft_isalnum.c \
				./ft_isalpha.c \
				./ft_isascii.c \
				./ft_isdigit.c \
				./ft_isprint.c \
				./ft_itoa.c \
				./ft_memset.c \
				./ft_putchar.c \
				./ft_putchar_fd.c \
				./ft_putendl.c \
				./ft_putendl_fd.c \
				./ft_putnbr.c \
				./ft_putnbr_fd.c \
				./ft_putstr.c \
				./ft_putstr_fd.c \
				./ft_strncat.c \
				./ft_strrchr.c \
				./ft_strchr.c \
				./ft_strcpy.c \
				./ft_strdup.c \
				./ft_strequ.c \
				./ft_striter.c \
				./ft_striteri.c \
				./ft_strlen.c \
				./ft_strmap.c \
				./ft_strmapi.c \
				./ft_strcat.c \
				./ft_strcmp.c \
				./ft_strncpy.c \
				./ft_strnequ.c \
				./ft_strnstr.c \
				./ft_strstr.c \
				./ft_tolower.c \
				./ft_toupper.c \
				./ft_strncmp.c \
				./ft_memset.c \
				./ft_bzero.c \
				./ft_memcpy.c \
				./ft_memccpy.c \
				./ft_memmove.c \
				./ft_memchr.c \
				./ft_memcmp.c \
				./ft_strlcat.c \
				./ft_memalloc.c \
				./ft_memdel.c \
				./ft_strnew.c \
				./ft_strdel.c \
				./ft_strclr.c \
				./ft_strsub.c \
				./ft_strjoin.c \
				./ft_strtrim.c \
				./ft_strsplit.c \
				./ft_lstnew.c \
				./ft_lstdelone.c \
				./ft_lstdel.c \
				./ft_lstadd.c \
				./ft_lstiter.c \
				./ft_lstmap.c \
				./ft_itoa_base.c \
				./ft_abs.c \
				./get_next_line.c

INC_NAME = ft_printf.h
OBJ_NAME = $(SRC_PRINTF:.c=.o)
OBJLIB_NAME = $(LIB_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_PRINTF))
LIB = $(addprefix $(LIB_PATH)/, $(LIB_NAME))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
OBJLIB = $(addprefix $(OBJLIB_PATH)/,$(OBJLIB_NAME))

all: $(NAME)

$(NAME): $(OBJ) $(OBJLIB)
	@ar rc $(NAME) $(OBJ) $(OBJLIB)
	@ranlib $(NAME)
	@echo "\033[1;34mlibft\t\033[1;33mCompilation\t\t\033[0;32m[OK]\033[0m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) $(INCLUDE) -o $@ -c $<

$(OBJLIB_PATH)/%.o: $(LIB_PATH)/%.c
	@mkdir $(OBJLIB_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) $(INCLUDE) -o $@ -c $<

clean:
	@rm -rf $(OBJ) $(OBJLIB)
	@echo "\033[1;34mlibft\t\033[1;33mCleaning obj\t\t\033[0;32m[OK]\033[0m"

fclean:
	@rm -rf ./obj $(NAME)
	@echo "\033[1;34mlibft\t\033[1;33mCleaning lib\t\t\033[0;32m[OK]\033[0m"

re: fclean all
