/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:01:36 by alpelliz          #+#    #+#             */
/*   Updated: 2024/01/22 12:53:19 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal() : _type("Default"){
	std::cout << "Animal default constructor called" << std::endl;
}


Animal::Animal(std::string type)
{
	_type = type;
	std::cout << _type << " Constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Default destroyer" << std::endl;
}

std::string Animal::getType() const
{
	return _type;
}


//void Animal::makeSound() const  //commented because it's pure virtual
//{
//	std::cout << "Animal MakeSound function here" << std::endl;
//};


