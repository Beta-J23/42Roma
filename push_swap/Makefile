# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 15:33:18 by alpelliz          #+#    #+#              #
#    Updated: 2023/04/21 15:35:47 by alpelliz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= push_swap.c check.c basic_moves_p.c basic_moves_r.c basic_moves_rr.c basic_moves_s.c push_swap_utils.c initializer.c sorting.c \
					number_3.c number_5.c num_filters.c sort_push.c looped_moves.c moving_convenience.c int_array_creator.c array_filler.c num_filters_2.c
OBJS			= $(SRCS:.c=.o)
EXTOBJS			= ft_printf/ft_printf.a ft_printf/*.o get_next_line/get_next_line.a get_next_line/*.o
TARGET			= push_swap

CC				= gcc -g
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

FT_PRINTF		= ft_printf/*.c
LIBFT			= libft/*.c


all: $(TARGET)

$(NAME) : all

$(TARGET):
	@$(CC) $(SRCS) $(CFLAGS) $(FT_PRINTF) $(LIBFT) -o $(TARGET)
	@printf "Ready.\n"

clean:
	@$(RM) $(TARGET)
	@printf 'clean: push_swap executable succesfully removed\n'

re: clean all

fclean:
	@$(RM) $(TARGET)
	@printf 'fclean: Target removed\n'

norm:
	@norminette -R CheckSourceForbiddenHeader $(SRCS) $(GNL) $(FT_PRINTF)
				
.PHONY:			all clean fclean re bonus norm totalclean