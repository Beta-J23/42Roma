# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_matrix.py                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/15 18:09:10 by alpelliz          #+#    #+#              #
#    Updated: 2023/12/20 14:59:10 by alpelliz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

if len(sys.argv) != 3:
    print("Error! Usage: python3 ft_matrix.py <n> <m>")
else:
    n = int(sys.argv[1]) + 1
    m = int(sys.argv[2]) + 1
    matrix = [[0 for _ in range(n)]for _ in range(m)]
    i = int(0)
    j = int(0)
    x = [0 for _ in range(n)]
    y = [0 for _ in range(m)]

    while(i < n - 1):
        while(j < m - 1):
            matrix[i][j] = float(input("Insert the element in position (" + str(i) +", " + str(j) +"): "))
            y[i] += matrix[i][j]
            j += 1
        j = 0
        i += 1

    i = 0
    j = 0

    while(j < m - 1):
        i = 0
        while(i < n - 1):
            x[j] += matrix[i][j]
            i+=1
        j+= 1
        
    print("The inserted matrix is: ")
    print(matrix[0])
    print(matrix[1])
    while (i < n - 1):
        print((matrix[i][0 : m - 1]))
        i += 1
    print("The sum over rows is:")
    print(y[0:n - 1])
    print("The sum over columns is:")
    print(x[0:m - 1])