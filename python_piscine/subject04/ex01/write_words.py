# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    write_words.py                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 18:04:02 by alpelliz          #+#    #+#              #
#    Updated: 2023/12/20 14:39:26 by alpelliz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

n = input("Insert an integer: ")
f = open("words.txt", "r")
fw = open("long_words.txt", "w")
print(f'The words longer than {n} have been written on "long_words.txt"')
for x in f:
    if len(x) - 1 > int(n):
        fw.write(x)
f.close()