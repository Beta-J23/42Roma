# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_print.py                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 14:59:39 by alpelliz          #+#    #+#              #
#    Updated: 2023/12/20 13:09:33 by alpelliz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

s = input("Insert a string: ")
n = input("Insert an integer: ")
n = int(n)
x = len(s) - n

if n > len(s):
    print("Error: index out of range") 
else:
    while (n <= x):
        print("{}" .format(s[n]), end="")
        n += 1
    print("")