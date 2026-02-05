# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_compare.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 11:41:52 by alpelliz          #+#    #+#              #
#    Updated: 2023/12/13 13:44:30 by alpelliz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

if len(sys.argv) != 3:
    print("Wrong number of args")
    exit()

x = float(sys.argv[1])
y = float(sys.argv[2])

if (x > y):
    print(f'{x} is greater than {y}')
elif (x == y):
    print(f'{x} is equal to {y}')
else:
    print(f'{x} is less than {y}')
