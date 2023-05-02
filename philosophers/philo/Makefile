# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 15:33:18 by alpelliz          #+#    #+#              #
#    Updated: 2023/05/02 17:24:10 by alpelliz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= main.c arg_checker.c log_printer.c
OBJS			= $(SRCS:.c=.o)
TARGET			= philo

CC				= gcc -g
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror


all: $(TARGET)

$(NAME) : all

$(TARGET): $(SRCS)
	@$(CC) $(SRCS) $(CFLAGS) -o $(TARGET)
	@printf "Ready.\n"

clean:
	@$(RM) $(TARGET)
	@printf 'clean: push_swap executable succesfully removed\n'

re: clean all

fclean: clean
	@printf 'fclean: target removed\n'

norm:
	@norminette -R CheckSourceForbiddenHeader $(SRCS)
				
.PHONY:			all clean fclean re bonus norm totalclean