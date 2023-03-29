# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 15:33:18 by alpelliz          #+#    #+#              #
#    Updated: 2023/03/29 14:25:09 by alpelliz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= main.c
OBJS			= $(SRCS:.c=.o)
EXTOBJS			= ft_printf/libftprintf.a ft_printf/*.o

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

FT_PRINTF		= ft_printf/libftprintf.a
LIBX			= -Imlx -c $< -o $@
LINK			= -Lmlx -lmlx -framework OpenGL -framework AppKit
#For object files, you could add the following rule to your makefile, assuming that you have the mlx source in a directory named mlx in the root of your project:


%.o: %.c
	$(CC) $(CFLAGS) $(LIBX)



all:
	$(CC) $(LINK) main.c
	./a.out

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