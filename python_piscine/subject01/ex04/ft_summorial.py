# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_summorial.py                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 13:54:19 by alpelliz          #+#    #+#              #
#    Updated: 2023/12/13 14:34:06 by alpelliz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

if len(sys.argv) != 2:
    print("Error! Usage: python3 ft_summorial.py <n>")
else:
    n = int(sys.argv[1])
    i = int(0)
    x = int(0)
    if n < 0:
        print("Error! n must be >= 0")
    else:
        while(i <= n):
            x += i
            i += 1
        print(f'The sum is: {x}')
    