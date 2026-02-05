/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:31:47 by alpelliz          #+#    #+#             */
/*   Updated: 2024/01/20 12:04:29 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    //std::string &stringREF = *stringPTR;
    std::string &stringREF = str;

    std::cout << "string address" << &str << std::endl;
    std::cout << "stringPTR address" << stringPTR << std::endl;
    std::cout << "stringREF address" << &stringREF << std::endl;
    std::cout << "str value: " << str << std::endl;
    std::cout << "stringPTR pointed value: " << *stringPTR << std::endl;
    std::cout << "stringREF pointed value: " << stringREF << std::endl;
}