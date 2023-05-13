# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 15:33:18 by alpelliz          #+#    #+#              #
#    Updated: 2023/05/13 16:34:59 by alpelliz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= main.c arg_checker.c log_printer.c utils.c initializer2.c threads.c routines4.c basic_utils.c
OBJS			= $(SRCS:.c=.o)
TARGET			= philo

CC				= gcc -g
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror


all: $(TARGET)

$(NAME) : all

$(TARGET): $(SRCS)
	@$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)
	@printf "Ready.\n"

clean:
	@$(RM) $(TARGET)
	@printf 'clean: philo executable succesfully removed\n'

re: clean all

fclean: clean
	@printf 'fclean: target removed\n'

norm:
	@norminette -R CheckSourceForbiddenHeader $(SRCS)
				
.PHONY:			all clean fclean re bonus norm totalclean