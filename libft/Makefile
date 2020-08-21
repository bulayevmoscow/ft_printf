# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/06 22:31:46 by kupsyloc          #+#    #+#              #
#    Updated: 2019/09/20 04:56:55 by kupsyloc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURSE = 		ft_putchar.c	\
				ft_bzero.c		\
				ft_memcpy.c		\
				ft_memset.c		\
				ft_putchar_fd.c	\
				ft_memccpy.c	\
				ft_memmove.c	\
				ft_memchr.c		\
				ft_isalpha.c	\
				ft_isdigit.c	\
				ft_isalnum.c	\
				ft_isascii.c	\
				ft_isprint.c	\
				ft_toupper.c	\
				ft_tolower.c	\
				ft_putnbr_fd.c	\
				ft_putstr_fd.c	\
				ft_putnbr.c		\
				ft_putstr.c		\
				ft_putendl.c	\
				ft_putendl_fd.c \
				ft_memcmp.c		\
				ft_strlen.c		\
				ft_strdup.c		\
				ft_strcpy.c		\
				ft_strncpy.c	\
				ft_strcat.c		\
				ft_strncat.c	\
				ft_strlcat.c	\
				ft_strchr.c		\
				ft_strrchr.c	\
				ft_strstr.c		\
				ft_strnstr.c	\
				ft_strcmp.c		\
				ft_strncmp.c	\
				ft_atoi.c		\
				ft_memalloc.c	\
				ft_memdel.c		\
				ft_strnew.c		\
				ft_strdel.c		\
				ft_strclr.c		\
				ft_striter.c	\
				ft_striteri.c	\
				ft_strmapi.c	\
				ft_strmap.c		\
				ft_strequ.c		\
				ft_strnequ.c	\
				ft_strsub.c		\
				ft_strjoin.c	\
				ft_strtrim.c	\
				ft_strsplit.c	\
				ft_itoa.c		\
				ft_lstnew.c		\
				ft_lstdelone.c	\
				ft_lstdel.c		\
				ft_lstadd.c		\
				ft_lstiter.c	\
				ft_lstmap.c		\
				ft_abs.c		\
				ft_strrev.c		\
				ft_sqrt.c		\
				ft_max.c		\
				ft_list_size.c	\
				
				

OUT_SOURSE = $(SOURSE:.c=.o)

INCLUDES = libft.h

all		:	$(NAME)

$(NAME)	:	
			gcc -Wall -Wextra -Werror -c $(SOURSE)  -I $(INCLUDES) 
			ar rc $(NAME) $(OUT_SOURSE) $@ $^
			ranlib $(NAME)

clean	:
			rm -rf $(OUT_SOURSE)

fclean	:	clean
			rm -rf $(NAME)
		

re		:	fclean	all

.PHONY: clean fclean re all

