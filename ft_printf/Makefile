# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 13:57:51 by alpelliz          #+#    #+#              #
#    Updated: 2022/06/07 13:08:37 by alpelliz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_putstuff.c ft_printf.c hex_conv.c
OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

norm:			norm
				norminette -R CheckSourceForbiddenHeader $(SRCS)


.PHONY:			all clean fclean re bonus norm
