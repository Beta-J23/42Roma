# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    point.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 14:21:06 by alpelliz          #+#    #+#              #
#    Updated: 2023/12/19 14:59:28 by alpelliz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y
    
if __name__== "__main__":
    Point.x = input("Insert the coordinates of the first point: ")
    Point.y = input("Insert the coordinates of the second point: ")
    i = 0
    while(Point.x[i] != ','):
        i += 1
    x1 = float(Point.x[:i])
    x2 = float(Point.x[i + 1:])

    i = 0
    while(Point.y[i] != ','):
        i += 1
    y1 = float(Point.y[:i])
    y2 = float(Point.y[i + 1:])

    d = (((x2-x1)**2) + (y2-y1)**2)**0.5 
    print(f'Their distance is: {d}')
