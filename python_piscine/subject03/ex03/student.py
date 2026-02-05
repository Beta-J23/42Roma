# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    student.py                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 16:56:58 by alpelliz          #+#    #+#              #
#    Updated: 2023/12/20 14:32:38 by alpelliz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

class Person:
    def __init__(self, first_name, last_name):
        self.first_name = first_name
        self.last_name = last_name
    def __str__(self):
        return (f'{self.first_name} {self.last_name}')

class Student(Person):
    def __init__(self, first_name, last_name, degree=None):
        super().__init__(first_name, last_name)
        self.degree = degree
    def __str__(self):
        if self.degree == None:
            return (f'{super().__str__()} is not registered to any course')
        else:
            return (f'{super().__str__()} is registered to {self.degree}')


if __name__ == "__main__":
    first_name = input("Insert first name: ")
    last_name = input("Insert last name: ")
    is_stud = input("Are you a student? (y/n)")
    while is_stud != 'y' and is_stud != 'n':
        is_stud = input('Please type "y" or "n": ')
    
    if is_stud == 'y':
        degree = input("Please insert your degree course: ")
        student = Student(first_name, last_name, degree)
        print(student)
    else:
        person = Person(first_name, last_name)
        print(person)        