# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/21 16:01:50 by alpelliz          #+#    #+#              #
#    Updated: 2024/07/25 13:01:56 by alpelliz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #




SRCS			= main.cpp src/Bureaucrat.cpp src/AForm.cpp src/ShrubberyCreationForm src/Robotomyrequest.cpp src/PresidentialPardonForm
OBJS			= $(SRCS:.c=.o)
TARGET			= Form

CC				= g++
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
