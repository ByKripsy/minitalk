# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouchet <mbouchet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 11:43:02 by mbouchet          #+#    #+#              #
#    Updated: 2024/01/29 13:22:01 by mbouchet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= minitalk
CNAME	:= client
SNAME	:= server
CC		:= clang
CFLAGS	:= -Wextra -Wall -Werror -g

LIBFT	:= ./libft
HEADERS	:= -I $(LIBFT)
LIBS	:= $(LIBFT)/libft.a

SRCS	:= client.c server.c
SRCS_P	:= $(addprefix srcs/, $(SRCS))
OBJS	:= $(SRCS_P:.c=.o)

GREEN	:= \033[1;32m

all: libft $(NAME)

libft:
	@cd $(LIBFT) && make

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "$(GREEN)$(notdir $<) compiled[0m ✔️\n"

$(NAME): $(OBJS)
	@$(CC) srcs/server.o $(LIBS) $(HEADERS) -o $(SNAME)
	@$(CC) srcs/client.o $(LIBS) $(HEADERS) -o $(CNAME)
	
run: all
	@./$(SNAME)
	
clean:
	@rm -f $(OBJS)
	@cd libft && make clean

fclean: clean
	@rm -f $(NAME)
	@cd libft && rm -f libft.a

re: clean all

.PHONY: all libft valgrind run clean fclean re