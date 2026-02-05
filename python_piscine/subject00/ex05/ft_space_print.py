# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_space_print.py                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 15:24:02 by alpelliz          #+#    #+#              #
#    Updated: 2023/12/12 15:39:50 by alpelliz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

s = input("Insert a string: ")
x = 20 - len(s)
x = int(x)
if x >= 0:
    while(x > 0):
        print(" ", end="")
        x -= 1
    while(x < len(s)):
        print("{}" .format(s[x]), end="")
        x += 1
    print("")
else:
    print(s[-20:])