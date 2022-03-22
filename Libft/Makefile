# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 13:57:51 by alpelliz          #+#    #+#              #
#    Updated: 2022/03/21 19:10:12 by alpelliz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_isalnum.c ft_isprint.c \
					ft_strlcat.c ft_strncmp.c  ft_atoi.c ft_isalpha.c ft_strnstr.c\
				      ft_strchr.c  ft_strlcpy.c ft_atoi.c ft_bzero.c ft_calloc.c \
					 ft_tolower.c   ft_isascii.c  ft_strdup.c ft_substr.c\
                    ft_strlen.c  ft_strrchr.c ft_memcpy.c ft_memchr.c  ft_strtrim.c\
					ft_toupper.c  ft_isdigit.c ft_memset.c  ft_memcmp.c ft_strjoin.c 
OBJS			= $(SRCS:.c=.o)

BONUS			=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
					ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
					ft_lstmap.c ft_lstnew.c ft_lstsize.c
BONUS_OBJS		= $(BONUS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus
