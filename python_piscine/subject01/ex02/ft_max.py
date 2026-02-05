# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_max.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 12:16:48 by alpelliz          #+#    #+#              #
#    Updated: 2023/12/13 13:41:46 by alpelliz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

if len(sys.argv) != 4:
    print("Error! Usage: python3 ft_max.py <x> <y> <z>")
else:
    x = float(sys.argv[1])
    y = float(sys.argv[2])
    z = float(sys.argv[3])
    max = x
    if max < y:
       max = y
    elif max < z:
        max = z
    print(f'the max is: {max}')