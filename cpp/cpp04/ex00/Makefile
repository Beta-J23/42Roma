# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/21 16:01:50 by alpelliz          #+#    #+#              #
#    Updated: 2024/01/21 17:30:52 by alpelliz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #




SRCS			= main.cpp src/Animal.cpp src/Wrong_Animal.cpp src/Dog.cpp src/Cat.cpp src/Wrong_Cat.cpp
OBJS			= $(SRCS:.c=.o)
TARGET			= Animal

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
