# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbessonn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/11 15:31:44 by cbessonn          #+#    #+#              #
#    Updated: 2023/02/08 15:36:03 by cbessonn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror 

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
		ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
		ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
		ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
		ft_strncmp.c ft_strcmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
		ft_toupper.c ft_swap.c ft_abs.c ft_str_array_free.c get_next_line/get_next_line_utils.c get_next_line/get_next_line.c

OBJ = $(SRC:.c=.o) 

BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
		ft_lstmap.c ft_lstnew.c ft_lstsize.c

BONUS_OBJ = $(BONUS:.c=.o)

AR = ar rcs

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I./includes -o $@ -c $<

$(NAME): $(OBJ)
	$(AR) $@ $^

bonus: $(BONUS_OBJ)
	$(AR) $(NAME) $^

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
