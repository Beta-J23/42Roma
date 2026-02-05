/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:01:43 by alpelliz          #+#    #+#             */
/*   Updated: 2024/01/21 16:51:33 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() : Animal("Dog"){
    std::cout << _type << "default constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << _type << " have been destroyed!!!" << std::endl;
}

void Dog::makeSound()const{
	std::cout << "Ti dico bau" << std::endl;
	system("afplay sound/dog.mp3");
}