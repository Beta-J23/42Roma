# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    circle.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 15:00:42 by alpelliz          #+#    #+#              #
#    Updated: 2023/12/19 16:23:13 by alpelliz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

class Circle:
    def __init__(self, center, radius):
        self.center = Point(center[0], center[1])
        self.radius = radius
    
    def __str__(self):
        return (f'Circle of center {self.center.x, self.center.y} and radius {self.radius}')

if __name__ == "__main__":
    circle = Circle((150, 100), 75)
    print(circle)