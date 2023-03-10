# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 15:33:18 by alpelliz          #+#    #+#              #
#    Updated: 2023/02/16 09:49:15 by alpelliz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= server.c client.c
OBJS			= $(SRCS:.c=.o)
EXTOBJS			= ft_printf/libftprintf.a libft/libft.a ft_printf/*.o libft/*.o
SERVER			= server.out
CLIENT			= client.out

SRC_C			=	client.c
SRC_S			=	server.c

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

DEST			= a.out

LIBFT = libft/libft.a
FT_PRINTF = ft_printf/libftprintf.a

all:			$(SERVER) $(CLIENT)

$(NAME): all

$(SERVER): $(EXTOBJS)
	gcc $(CFLAGS) $(SRC_S) $(LIBFT) $(FT_PRINTF) -o $(SERVER)
	@printf "$(_SUCCESS) server ready.\n"
#$(DEST): $(OBJS) $(LIBFT) $(FT_PRINTF)
#	gcc $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) -o $(DEST)

$(CLIENT): $(EXTOBJS)
	@ $(CC) $(CFLAGS) $(SRC_C) $(LIBFT) $(FT_PRINTF) -o $(CLIENT)
	@printf "$(_SUCCESS) client ready.\n"

$(LIBFT):
	make -C libft

$(FT_PRINTF):
	make -C ft_printf

$(EXTOBJS):		$(FT_PRINTF) 

clean:
					$(RM) $(OBJS) $(EXTOBJS) $(SERVER) $(CLIENT)

execute :			execute
					./a.out

totalclean:
					$(RM)

norm:			norm
				norminette -R CheckSourceForbiddenHeader $(SRCS)
				
.PHONY:			all clean fclean re bonus norm totalclean execute