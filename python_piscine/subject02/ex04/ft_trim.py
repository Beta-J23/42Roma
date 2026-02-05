# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_trim.py                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/16 11:28:57 by alpelliz          #+#    #+#              #
#    Updated: 2023/12/20 14:24:39 by alpelliz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

def trim(my_list):
    n = len(my_list)

if __name__ == "__main__":
    n = len(sys.argv)
    if n < 3:
        print("Error! You must insert at least 2 values")
    else:
        my_list = [0 for _ in range(n)]
        i = int(0)
        while (i < n):
            my_list[i] = sys.argv[i]
            i += 1
        trim(my_list)
        print(f'The new list is: {my_list[2:n - 1]}')
