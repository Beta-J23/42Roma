# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 15:33:18 by alpelliz          #+#    #+#              #
#    Updated: 2023/04/05 19:35:44 by alpelliz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= main.c key_dealer.c map_function.c starter.c utils.c
OBJS			= $(SRCS:.c=.o)
EXTOBJS			= ft_printf/libftprintf.a ft_printf/*.o get_next_line/get_next_line.a get_next_line/*.o

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

GET_NEXT_LINE	= get_next_line/get_next_line.a
FT_PRINTF		= ft_printf/libftprintf.a
LIBX			= -Imlx -c $< -o $@
LINK			= -Lmlx -lmlx -framework OpenGL -framework AppKit
#For object files, you could add the following rule to your makefile, assuming that you have the mlx source in a directory named mlx in the root of your project:


%.o: %.c
	$(CC) $(CFLAGS) $(LIBX)



all:
	$(CC) $(LINK) main.c key_dealer.c starter.c counters.c map_checker_mod.c map_checker_mod_helper.c map_function.c utils.c ft_printf/*.c get_next_line/*.c
#	./a.out

#To link with the required internal macOS API:
#$(NAME): $(OBJS)
#		$(CC)  -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(OBJS) $(NAME)

#all:		$(NAME)
#$(NAME): $(OBJS)
#	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

#$(NAME): all

#$(SO_LONG):
#	@make -C libft
#	@make -C ft_printf
#	@gcc $(CFLAGS) $(SRC_S) $(FT_PRINTF) -o $(SERVER)
#	@printf "$(_SUCCESS) ready to play.\n"

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