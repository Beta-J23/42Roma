# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 15:33:18 by alpelliz          #+#    #+#              #
#    Updated: 2023/04/12 13:16:06 by alpelliz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= push_swap.c
OBJS			= $(SRCS:.c=.o)
EXTOBJS			= ft_printf/ft_printf.a ft_printf/*.o get_next_line/get_next_line.a get_next_line/*.o
TARGET			= push_swap

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

FT_PRINTF		= ft_printf/*.c
LIBFT			= libft/*.c


all: $(TARGET)

$(NAME) : all

$(TARGET):
	@$(CC) $(CFLAGS) $(SRCS) $(FT_PRINTF) $(LIBFT) -o $(TARGET)
	@printf "Ready.\n"

clean:
	@$(RM) $(TARGET)
	@printf 'clean: so_long executable succesfully removed\n'

re: clean all

fclean:
	@$(RM) $(TARGET)
	@printf 'fclean: Target removed\n'

norm:
	@norminette -R CheckSourceForbiddenHeader $(SRCS) $(GNL) $(FT_PRINTF)
				
.PHONY:			all clean fclean re bonus norm totalclean