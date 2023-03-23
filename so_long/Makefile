# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 15:33:18 by alpelliz          #+#    #+#              #
#    Updated: 2023/03/17 11:56:04 by alpelliz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= so_long.c
OBJS			= $(SRCS:.c=.o)
EXTOBJS			= ft_printf/libftprintf.a ft_printf/*.o

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

FT_PRINTF = ft_printf/libftprintf.a

all:			$(SERVER) $(CLIENT)

$(NAME): all

$(SO_LONG):
	@make -C libft
	@make -C ft_printf
	@gcc $(CFLAGS) $(SRC_S) $(FT_PRINTF) -o $(SERVER)
	@printf "$(_SUCCESS) ready to play.\n"

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