# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_ext_pos.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 15:20:53 by alpelliz          #+#    #+#              #
#    Updated: 2023/12/20 14:17:02 by alpelliz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

if len(sys.argv) == 1:
    print("Error! Usage: python3 ft_ext_pos.py <x1> ... <xn>")
else:
    arg_list = sys.argv[1:]
    n = len(arg_list)
    i = 0
    x = int(0)
    y = 0
    z = int(0)
    j = 0
    while (i < n):
        if z > int(arg_list[i]):
            z = int(arg_list[i])
            j = i
        if x < int(arg_list[i]):
            x = int(arg_list[i])
            y = i
        i += 1

    print("The min is " + str(z) + " and its position is " + str(j))
    print("The max is " + str(x) + " and its position is " + str(y))