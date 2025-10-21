# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/29 12:23:54 by opaulman          #+#    #+#              #
#    Updated: 2025/10/20 14:33:52 by opaulman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pushswap.a

SRC = push_swap.c createstack.c error_check.c radix.c operations.c chartobinary.c \
checksorted.c mapping.c smalldigits.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
PRINT = printf
PRINTF_MAKE = make -C $(PRINT)

all:	$(NAME)

$(NAME):	$(OBJ)	$(PRINT)/ft_printf.a
		cp $(PRINT)/ft_printf.a $(NAME)
		ar rcs $(NAME) $(OBJ)

$(PRINT)/ft_printf.a:
				$(PRINTF_MAKE)
%.o: %.c
	$(CC)	$(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(PRINTF_MAKE) clean
fclean: 
	rm -f $(NAME) $(OBJ)
	$(PRINTF_MAKE) fclean
re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re