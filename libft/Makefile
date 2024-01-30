# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouchet <mbouchet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 13:15:57 by mbouchet          #+#    #+#              #
#    Updated: 2024/01/25 17:22:43 by mbouchet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= libft.a

CC		:= clang
CFLAGS	:= -Wall -Wextra -Werror 
AR		:= ar rcs

RESET	:= \033[0m
RED		:= \033[1;31m
GREEN	:= \033[1;32m
YELLOW	:= \033[1;33m
CYAN	:= \033[1;36m

SRCS	:=  ft_printf/basic_funcs.c \
			ft_printf/ft_printf.c \
			ft_printf/ft_putptr.c \
			libft/ft_atoi_base.c \
			libft/ft_atoi.c \
			libft/ft_bzero.c \
			libft/ft_calloc.c \
			libft/ft_free.c \
			libft/ft_isalnum.c \
			libft/ft_isalpha.c \
			libft/ft_isascii.c \
			libft/ft_isdigit.c \
			libft/ft_islower.c \
			libft/ft_isprint.c \
			libft/ft_isspace.c \
			libft/ft_isupper.c \
			libft/ft_itoa.c \
			libft/ft_lstadd_back.c \
			libft/ft_lstadd_front.c \
			libft/ft_lstclear.c \
			libft/ft_lstdelone.c \
			libft/ft_lstiter.c \
			libft/ft_lstlast.c \
			libft/ft_lstmap.c \
			libft/ft_lstnew.c \
			libft/ft_lstsize.c \
			libft/ft_memchr.c \
			libft/ft_memcmp.c \
			libft/ft_memcpy.c \
			libft/ft_memmove.c \
			libft/ft_memset.c \
			libft/ft_putchar_fd.c \
			libft/ft_putendl_fd.c \
			libft/ft_putnbr_fd.c \
			libft/ft_putstr_fd.c \
			libft/ft_split.c \
			libft/ft_strchr.c \
			libft/ft_strdup.c \
			libft/ft_striteri.c \
			libft/ft_strjoin.c \
			libft/ft_strlcat.c \
			libft/ft_strlcpy.c \
			libft/ft_strlen.c \
			libft/ft_strmapi.c \
			libft/ft_strncmp.c \
			libft/ft_strnstr.c \
			libft/ft_strrchr.c \
			libft/ft_strtrim.c \
			libft/ft_substr.c \
			libft/ft_tolower.c \
			libft/ft_toupper.c 
					  
OBJS	:= $(SRCS:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< && printf "$(GREEN)$(notdir $<) compiled[0m ✔️\n"

$(NAME): $(OBJS)
	@echo "$(GREEN)Compilation $(RESET)of $(YELLOW)$(NAME) $(RESET)..."
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)$(NAME) created[0m ✔️"

all: $(NAME)

bonus: all

clean:
	@rm -f $(OBJS)
	@! test -f $(NAME) || echo "$(RED)Deleting $(CYAN)$(NAME)$(RESET) objs ✔️"

fclean:	clean
	@rm -f $(NAME)
	@echo "$(RED)Deleting $(CYAN)$(NAME)$(RESET) binary ✔️"

re:	fclean all

.PHONY:	all bonus clean fclean re