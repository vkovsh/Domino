# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/08 11:54:49 by vkovsh            #+#    #+#              #
#    Updated: 2018/09/08 11:54:52 by vkovsh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	domino

CC					=	gcc
CC_FLAGS			=	-Wall -Werror -Wextra

SRC_PATH			=	./srcs/

INC_PATH			=	./includes/ $(LIBFTPRINTF_PATH)includes/ $(LIBFT_PATH)includes/
OBJ_PATH			=	./obj/
LIBFTPRINTF_PATH	=	./libftprintf/
LIBFT_PATH			=	$(LIBFTPRINTF_PATH)/libft/

OBJ					=	$(addprefix $(OBJ_PATH),$(OBJ_NAME))

INC					=	$(addprefix -I, $(INC_PATH))

OBJ_NAME			=	$(SRC_NAME:.c=.o)

SRC_NAME			=	main.c

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFTPRINTF_PATH)
	@$(CC) -o $(NAME) $(OBJ) $(LIBFTPRINTF_PATH)libftprintf.a
	@echo "Compiling" [ $(NAME) ]

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC)
	@echo "Linking" [ $< ]

clean:
	@make -C $(LIBFTPRINTF_PATH) clean
	@rm -rf $(OBJ_PATH)
	@echo "Cleaning obj [ $(NAME) ]..."

fclean: clean
	@rm -f $(NAME)
	@echo "Remove [ $(NAME) ]..."

re: fclean all
