# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_print.py                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 14:10:37 by alpelliz          #+#    #+#              #
#    Updated: 2023/12/12 14:30:08 by alpelliz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

s = input("Insert a string: ")
n = input("Insert an integer: ")
n = int(n)
x = len(s)
if n > x:
    print("Error: index out of range")
else:
    print("{}".format(s[n]), "{}".format(s[x - n]))
