/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wrong_Animal.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:01:36 by alpelliz          #+#    #+#             */
/*   Updated: 2024/01/21 17:32:33 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Wrong_Animal.hpp"

Wrong_Animal::Wrong_Animal() : _type("Wrong"){
	std::cout << "Animal default constructor called" << std::endl;
}

Wrong_Animal::Wrong_Animal(std::string type)
{
	_type = type;
	std::cout << _type << " Constructor called" << std::endl;
}

Wrong_Animal::~Wrong_Animal()
{
	std::cout << "Wrong animal Default destroyer" << std::endl;
}

std::string Wrong_Animal::getType() const
{
	return _type;
}

void Wrong_Animal::makeSound() const
{
	std::cout << "Wrong_Animal MakeSound function here" << std::endl;
};

