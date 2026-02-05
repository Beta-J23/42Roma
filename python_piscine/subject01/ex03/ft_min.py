# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_min.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 13:46:12 by alpelliz          #+#    #+#              #
#    Updated: 2023/12/20 14:48:56 by alpelliz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

def my_min(x=0, y=0, z=0):
    min = x
    if min > y:
        min = y
    if min > z:
        min = z
    return (min)

if __name__ == "__main__": 
    if len(sys.argv) != 4:
        print("Error! Usage: python3 ft_min.py <x> <y> <z>")
    else:
        x = float(sys.argv[1])
        y = float(sys.argv[2])
        z = float(sys.argv[3])
        #my_min(x, y, z)
        print(f'The min is: {my_min(x, y, z)}')