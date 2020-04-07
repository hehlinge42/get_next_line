# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hehlinge <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/02 21:32:05 by hehlinge          #+#    #+#              #
#    Updated: 2019/10/21 13:33:06 by hehlinge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = gnl_demo

SRC_DIR = ./srcs/

SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))

SRC_FILES =	get_next_line.c \
			main.c


OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

OBJ_FILES = $(SRC_FILES:.c=.o)

OBJ_DIR = objs/

INCLS = $(INC_DIR)get_next_line.h

INC_DIR = includes/

LIB = $(addprefix $(LIB_DIR), libft.a)

LIB_INCLS = $(LIB_DIR)$(INC_DIR)

LIB_DIR = libft/

all: $(NAME)

$(NAME): $(INCLS) $(LIB_INCLS) $(SRCS) $(LIB)
	@/bin/echo "make $(notdir $(NAME))"
	@rm -f auteur
	@echo hehlinge > auteur
	@mkdir -p objs
	@make -j --no-print-directory objects
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ $(OBJS) $(LIB)

$(LIB): FORCE
	@make -j --no-print-directory -C $(LIB_DIR)

objects: $(OBJS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCLS)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIB_INCLS) -o $@ -c $<

clean: FORCE
	@/bin/echo "make clean $(notdir $(NAME))"
	@rm -rf $(OBJ_DIR)
	@make clean -j --no-print-directory -C $(LIB_DIR)

fclean: clean
	@/bin/echo "make fclean $(notdir $(NAME))"
	@make fclean -j --no-print-directory -C $(LIB_DIR)
	@rm -f $(NAME)


re: FORCE
	@/bin/echo "make re $(notdir $(NAME))"
	@make -j --no-print-directory fclean
	@make -j --no-print-directory all

FORCE:
