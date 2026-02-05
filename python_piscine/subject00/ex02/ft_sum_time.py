# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_sum_time.py                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 13:58:33 by alpelliz          #+#    #+#              #
#    Updated: 2023/12/12 14:06:16 by alpelliz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


h = input("Insert hours: ")
min = input("Insert minutes: ")
sec = input("Insert seconds: ")
h = int(h)
min = int(min)
sec = int(sec)
print(f'Total seconds: {(h * 3600) + (min * 60) + sec}')

