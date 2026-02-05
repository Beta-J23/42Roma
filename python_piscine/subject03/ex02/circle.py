# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    circle.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 16:25:07 by alpelliz          #+#    #+#              #
#    Updated: 2023/12/20 14:29:59 by alpelliz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

class Circle:
    def __init__(self, center, radius):
        self.center = Point(center[0], center[1])
        self.radius = radius
    def contains(self, point):
        return (((point.x - self.center.x)**2) + ((point.y - self.center.y)**2)) <= self.radius**2

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Error! Bad arguments")
    else:
        point = Point(float(sys.argv[1]), float(sys.argv[2]))
        circle = Circle((0, 0), 1)
        if circle.contains(point):
            print(f'The Point ({sys.argv[1]}, {sys.argv[2]}) lies in the Circle of center (0, 0) and radius 1')
        else:
            print(f'The Point ({sys.argv[1]}, {sys.argv[2]}) lies out of the Circle of center (0, 0) and radius 1')
            