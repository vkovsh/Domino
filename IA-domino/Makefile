# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lle-blev <lle-blev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/13 17:03:49 by lle-blev          #+#    #+#              #
#    Updated: 2015/11/26 09:55:29 by lle-blev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# compiler
CC = clang++
# file type
FT = cpp
# flags
#FLAGS = -Wall -Wextra -Werror
FLAGS = -std=c++11
FLAGS += -O3
FLAGS += -g

# executable
NAME = dominoAI


# to compile files
SRC = main.cpp
SRC += Lexer.cpp
SRC += AI.cpp
SRC += Domino.cpp
SRC += Tools.cpp

# header files
HDR = Lexer.hpp
HDR += AI.hpp
HDR += Domino.hpp
HDR += Tools.hpp

# objects files
OBJS = $(SRC:.$(FT)=.o)

# main rule
all: $(NAME)

# rebuild your bin
re: fclean $(NAME)

# reclone submodule and rebuild
rere: ffclean $(NAME)

# compile lib
$(NAME): $(OBJS)
	$(CC) -o $@ $(OBJS)
	@echo "\033[36m$@ - complete\033[0m"

# making o files
%.o: %.$(FT) $(HDR)
	@$(CC) -o $@ -c $< $(FLAGS)
	@echo $< "updated!"

# protect commands
.PHONY: all re rere clean fclean

# clean o files
clean:
	@rm -rf $(OBJS)

# clean exec file and library
fclean: clean
	@rm -rf $(NAME)

