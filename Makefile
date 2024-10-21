# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brappo <brappo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 18:17:04 by brappo            #+#    #+#              #
#    Updated: 2024/01/25 11:43:16 by brappo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef NAME
	NAME	= 	libft.a
endif
NAME_GNL = gnl.a
NAME_LIST = list.a
NAME_PRINTF = printf.a
NAME_ALL = extendedlibft.a
CC		= 	cc
CFLAGS	+= 	-Wall -Wextra -Werror
INCLUDES = -IINCLUDE
SRC_FOLDER = MANDATORY/
LIST_FOLDER = t_list/
PERSO_FOLDER = PERSO/
GNL_FOLDER = GET_NEXT_LINE/
PRINTF_FOLDER = PRINTF/
SRCS_FILES		= 	ft_atoi.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_itoa.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memmove.c \
				ft_memset.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_split.c \
				ft_strchr.c \
				ft_strdup.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_putchar.c \
				ft_strlen.c
				
LIST_FILES	=	add_lst.c \
				add_node.c \
				create_list.c \
				create_node.c \
				find_node_index.c \
				for_each.c \
				free_list.c \
				lst_count_value.c \
				lst_element_at.c \
				lst_find_all.c \
				lst_find_first.c \
				lst_insert.c \
				lst_remove_at.c \
				lst_remove.c \
				set_each.c \
				to_array.c \
				to_list.c \
				lst_get_last.c

GNL_FILES = get_next_line.c \
			get_next_line_utils.c

PRINTF_FILES = 	ft_abs.c \
				ft_cast_ul.c \
				show_string.c \
				ft_get_flags.c \
				ft_is_in_set.c \
				ft_itoa_base.c \
				ft_padding.c \
				ft_precision.c \
				ft_print_args.c \
				ft_printf.c

PERSO_FILES =	print_array.c \
				read_file.c

PERSO_SRCS = $(addprefix $(PERSO_FOLDER),$(PERSO_FILES))

SRCS =  $(addprefix $(SRC_FOLDER),$(SRCS_FILES))

LIST_SRCS = $(addprefix $(LIST_FOLDER),$(LIST_FILES))

GNL_SRCS = $(addprefix $(GNL_FOLDER),$(GNL_FILES))

PRINTF_SRCS = $(addprefix $(PRINTF_FOLDER),$(PRINTF_FILES))

PERSO_OBJS	=	$(PERSO_SRCS:.c=.o)

LIST_OBJS	=	$(LIST_SRCS:.c=.o)

GNL_OBJS	=	$(GNL_SRCS:.c=.o)

PRINTF_OBJS = 	$(PRINTF_SRCS:.c=.o)

OBJS = $(SRCS:.c=.o)

ifdef GNL
	OBJS += $(GNL_OBJS)
endif
ifdef LIST
	OBJS += $(LIST_OBJS)
endif
ifdef PRINTF
	OBJS += $(PRINTF_OBJS)
endif
ifdef PERSO
	OBJS += $(PERSO_OBJS)
endif

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all:
	make GNL=1 LIST=1 PRINTF=1 PERSO=1 NAME=$(NAME_ALL) $(NAME_ALL)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

bonus : list

list :
	make LIST=1 NAME=$(NAME_LIST) $(NAME_LIST)

get_next_line: gnl

gnl :
	make GNL=1 NAME=$(NAME_GNL) $(NAME_GNL)

printf:
	make PRINTF=1 NAME=$(NAME_PRINTF) $(NAME_PRINTF)

clean:
	rm -f $(OBJS) $(LIST_OBJS) $(GNL_OBJS) $(PRINTF_OBJS) $(PERSO_OBJS) $(LIBFT_OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_ALL)
	rm -f $(NAME_GNL)
	rm -f $(NAME_LIST)
	rm -f $(NAME_PRINTF)

re: fclean all

.PHONY: all clean fclean re
