# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    print_words.py                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 18:17:21 by alpelliz          #+#    #+#              #
#    Updated: 2023/12/20 14:40:20 by alpelliz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

file_name = input("Insert file name: ")
try:
    f = open(file_name, "r")
    n = input("Insert an integer: ")
    print(f'The words longer than {n} are the following: ')
    for x in f:
        if len(x) - 1 > int(n):
            print(x, end='')
    f.close()
except:
    print("Error! The specified file does not exist!")