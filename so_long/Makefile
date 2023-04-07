# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 15:33:18 by alpelliz          #+#    #+#              #
#    Updated: 2023/04/06 20:41:45 by alpelliz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= main.c key_dealer.c starter.c counters.c map_checker_mod.c map_checker_mod_helper.c \
					map_function.c map_function_helper.c utils.c 
OBJS			= $(SRCS:.c=.o)
EXTOBJS			= ft_printf/ft_printf.a ft_printf/*.o get_next_line/get_next_line.a get_next_line/*.o
TARGET			= so_long

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

GNL				= get_next_line/*.c
FT_PRINTF		= ft_printf/*.c
LIBX			= -Imlx -c $< -o $@
LINK			= -Lmlx -lmlx -framework OpenGL -framework AppKit


all: $(TARGET)

$(NAME) : all

$(TARGET):
	@$(CC) $(CFLAGS) $(LINK) $(SRCS) $(GNL) $(FT_PRINTF) -o $(TARGET)
	@printf 'Compilation done!\nso_long executable succesfully created!\n'
	@printf "Ready to play.\n"

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