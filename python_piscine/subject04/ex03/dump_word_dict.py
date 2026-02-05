# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    dump_word_dict.py                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 18:23:14 by alpelliz          #+#    #+#              #
#    Updated: 2023/12/20 12:56:21 by alpelliz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import pickle

dict = {}
lenght = 0
f = open("words.txt", "r")
for x in f:
    lenght = len(x) - 1
    if lenght in dict:
        dict[lenght] += 1
    else:
        dict[lenght] = 1

array_key = [k for k in dict]
array_key.sort()
dict_sort = {k: 0 for k in array_key}
for k, v in dict.items():
    for x in dict_sort:
        if k == x:
            dict_sort[x] = v

with open("word_count.pickle", "wb") as g:
    pickle.dump(dict_sort, g)
f.close()