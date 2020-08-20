# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aghar <aghar@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/13 21:41:48 by aghar             #+#    #+#              #
#    Updated: 2020/08/20 22:24:05 by aghar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/
FT_LIB = $(addprefix $(LIBFT),libft.a)
FT_INK = -I ./libft
FT_LNK = -L ./libft -lft
DIR_S = ./src/
DIR_O = ./obj/
HEADER = ./includes/
SOURCES =	check_flags.c check_flags_extra.c ft_itoa_external.c  parse.c printf.c pusher_c_s_p.c \
			pusher_diuox.c  pusher_f.c   ft_str_concat.c   parse_extra.c    \
			stars_manager.c  ft_itoa_external.c pusher_c_s_p_extra.c norm.c

            
OBJS = $(addprefix $(DIR_O),$(SOURCES:.c=.o))
all: obj $(FT_LIB) $(NAME)
obj:
	@mkdir -p $(DIR_O)
$(DIR_O)%.o:$(DIR_S)%.c
	@$(CC) $(FLAGS)  $(FT_INK) -I $(HEADER) -o $@ -c $<
$(FT_LIB):
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
clean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFT)
fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)
re: fclean all
.PHONY: fclean re all clean
