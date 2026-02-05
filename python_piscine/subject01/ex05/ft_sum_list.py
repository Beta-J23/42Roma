# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_sum_list.py                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 14:34:55 by alpelliz          #+#    #+#              #
#    Updated: 2023/12/13 15:14:43 by alpelliz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys


def sum_list(list):
    z = 0
    for i in range(len(list)):
        z += list[i] 
    return (z)



if __name__ == "__main__":
    my_list = [0, 0]

    while(1):
        my_list[0] = int(input("Insert integer: "))
        my_list[1] = sum_list(my_list)
        if my_list[0] == 0:
            print(f'The sum is: {my_list[1]}')
            break
            
        