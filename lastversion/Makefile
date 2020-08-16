# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artemignatev <artemignatev@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/06 22:31:46 by kupsyloc          #+#    #+#              #
#    Updated: 2020/08/16 14:15:39 by artemignate      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURSE =  check_flags.c ft_itoa_external.c parse.c \
			printf.c pusher_c_s_p.c pusher_diuox.c \
			pusher_f.c stars_manager.c ft_atoi.c \
			ft_isdigit.c ft_putchar.c ft_strdup.c \
			ft_strjoin.c ft_strlen.c ft_strnew.c \
			ft_strsub.c ft_memcpy.c ft_putchar_fd.c \
			check_flags_extra.c pusher_c_s_p_extra.c \
			parse_extra.c 
				
				

OUT_SOURSE = $(SOURSE:.c=.o)

INCLUDES = header.h

all		:	$(NAME)

$(NAME)	:	
			gcc -c $(SOURSE)  -I $(INCLUDES) 
			ar rc $(NAME) $(OUT_SOURSE) $@ $^
			ranlib $(NAME)

clean	:
			rm -rf $(OUT_SOURSE)

fclean	:	clean
			rm -rf $(NAME)

re		:	fclean	all

.PHONY: clean fclean re all

