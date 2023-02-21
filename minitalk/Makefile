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

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

DEST			= a.out

LIBFT = libft/libft.a
FT_PRINTF = ft_printf/libftprintf.a

all:				$(DEST)

$(DEST): $(OBJS) $(LIBFT) $(FT_PRINTF)
	gcc $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) -o $(DEST)

$(LIBFT):
	make -C libft

$(FT_PRINTF):
	make -C ft_printf

$(EXTOBJS):		$(FT_PRINTF) 

clean:
					$(RM) $(OBJS) $(EXTOBJS)

execute :			execute
					./a.out

totalclean:
					$(RM)

norm:			norm
				norminette -R CheckSourceForbiddenHeader $(SRCS)
				
.PHONY:			all clean fclean re bonus norm totalclean execute