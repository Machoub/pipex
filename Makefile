# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: machouba <machouba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 12:16:13 by machouba          #+#    #+#              #
#    Updated: 2024/06/03 15:00:00 by machouba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -I$(LIBFT_PATH)/inc -I./include
RM			=	rm -f

LIBFT_PATH	=	./libft
LIBFT		=	$(LIBFT_PATH)/libft.a

SRC			=	srcs/pipex.c \
				srcs/utils.c \
				srcs/wait.c

OBJ			=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	@$(MAKE) clean -C $(LIBFT_PATH)
	$(RM) $(OBJ)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
