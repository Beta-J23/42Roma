# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_palindrome.py                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 15:20:53 by alpelliz          #+#    #+#              #
#    Updated: 2023/12/20 14:55:47 by alpelliz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

def is_palindrome(string):
    string = string.replace(' ', '')
    if string == string[::-1]:
        return (True)
    else:
        return (False)
    
if __name__ == "__main__":
    if len(sys.argv) == 2:
        string = sys.argv[1]
        if is_palindrome(string) == True:
            #print(f'The string {string} is palindrome')
            print("The string " + string + " is palindrome")
        else:
            #print(f'The string {string} is not palindrome')
            print("The string " + string + " is not palindrome")
    else: 
        print("Error! Insert just 1 string!")