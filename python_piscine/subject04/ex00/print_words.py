# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    print_words.py                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 17:52:49 by alpelliz          #+#    #+#              #
#    Updated: 2023/12/20 14:37:20 by alpelliz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


n = input("Insert an integer: ")
f = open("words.txt", "r")
print(f'The words longer than {n} are the following: ')
for x in f:
    if len(x) - 1 > int(n):
        print(x, end='')
f.close()