/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:01:40 by alpelliz          #+#    #+#             */
/*   Updated: 2024/01/21 16:51:27 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat() : Animal("Cat"){
    std::cout << _type << "default constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << _type << " have been destroyed!!!" << std::endl;
}

void Cat::makeSound()const{
	std::cout << "Ti dico miao" << std::endl;
	system("afplay sound/cat.wav");
}