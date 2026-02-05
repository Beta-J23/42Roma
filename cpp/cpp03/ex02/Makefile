# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/20 16:02:43 by alpelliz          #+#    #+#              #
#    Updated: 2024/01/21 14:37:57 by alpelliz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS			= main.cpp src/ClapTrap.cpp src/ScavTrap.cpp src/FragTrap.cpp
OBJS			= $(SRCS:.c=.o)
TARGET			= The_legend_of_Al_John_Jack_Frank_and_Pippo

CC				= c++
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -std=c++98

all: $(TARGET)

$(NAME) : all

$(TARGET): $(SRCS)
	@$(CC) $(SRCS) $(CFLAGS) -o $(TARGET)
	@printf "Ready.\n"

clean:
	@$(RM) $(TARGET)
	@printf 'clean: executable succesfully removed\n'

re: clean all

fclean: clean
	@printf 'fclean: target removed\n'

.PHONY:			all clean fclean re%
