# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 15:33:18 by alpelliz          #+#    #+#              #
#    Updated: 2023/03/13 15:08:32 by alpelliz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= server.c client.c
OBJS			= $(SRCS:.c=.o)
EXTOBJS			= ft_printf/libftprintf.a libft/libft.a ft_printf/*.o libft/*.o
SERVER			= server
CLIENT			= client

SRC_C			=	client.c
SRC_S			=	server.c

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

LIBFT = libft/libft.a
FT_PRINTF = ft_printf/libftprintf.a

all:			$(SERVER) $(CLIENT)

$(NAME): all

$(SERVER):
	@make -C libft
	@make -C ft_printf
	@gcc $(CFLAGS) $(SRC_S) $(LIBFT) $(FT_PRINTF) -o $(SERVER)
	@printf "$(_SUCCESS) server ready.\n"

$(CLIENT):
	@ $(CC) $(CFLAGS) $(SRC_C) $(LIBFT) $(FT_PRINTF) -o $(CLIENT)
	@printf "$(_SUCCESS) client ready.\n"


clean:
	@make -C libft clean
	@make -C ft_printf clean
	$(RM) $(OBJS) $(EXTOBJS) $(SERVER) $(CLIENT)
	@printf "$(SUCCESS) Objects deleted"


totalclean:
					$(RM)

norm:			norm
				norminette -R CheckSourceForbiddenHeader $(SRCS)
				
.PHONY:			all clean fclean re bonus norm totalclean