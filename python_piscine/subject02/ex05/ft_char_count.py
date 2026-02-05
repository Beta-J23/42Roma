# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_char_count.py                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/16 12:02:54 by alpelliz          #+#    #+#              #
#    Updated: 2023/12/20 14:26:17 by alpelliz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys
import string

ascii_dict = {chr(i): i for i in range(128)}

if len(sys.argv) != 2:
    print("Error! No string given")
else:
    arg_str = sys.argv[1].lower()
    i = 0
    print("Char count:")
    for key in ascii_dict:
        n = 0
        i = 0
        while (i < len(arg_str)):
            if arg_str[i] == key:
                n += 1
            i += 1
        if (n > 0):
            print(f'{key} : {n}')
