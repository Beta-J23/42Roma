# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_sorted.py                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/15 21:07:34 by alpelliz          #+#    #+#              #
#    Updated: 2023/12/20 15:22:27 by alpelliz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

if len(sys.argv) < 3:
    print("Error! You must insert at least 2 numbers")
else:
    arr = [0 for _ in range(1, len(sys.argv))]
    for i in range(1, len(sys.argv)):
        arr[i - 1] = int(sys.argv[i])
    
    if arr == sorted(arr, reverse=True):
        print("The inserted sequence is sorted!")
    else:
        print("The inserted sequence is not sorted!")
        print(f'The correct order is {sorted(arr, reverse=True)}')