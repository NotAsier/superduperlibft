# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 10:19:53 by aarranz-          #+#    #+#              #
#    Updated: 2023/09/20 15:14:40 by aarranz-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SOURCES =\
	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
	ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c\
	 ft_strnstr.c ft_strrchr.c \
	ft_strdup.c ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_striteri.c\
	ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memset.c ft_memmove.c\
	ft_bzero.c ft_toupper.c ft_tolower.c\
	ft_atoi.c \
	ft_calloc.c\
	ft_substr.c\
	ft_itoa.c\
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
	ft_split.c\
	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c\
	ft_lstlast_bonus.c ft_lstadd_back_bonus.c\
	ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c\
	ft_printf.c ft_printf_hex.c ft_printf_ptr.c ft_printf_putunbr_fd.c ft_printf_utils.c\
	get_next_line.c
	
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) -r $@ $?
	rm -f $(OBJECTS)

%.o: %.c
	$(CC) -c $(CFLAGS) $?


fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re