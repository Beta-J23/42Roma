/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:01:43 by alpelliz          #+#    #+#             */
/*   Updated: 2024/01/22 14:00:24 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() : Animal("Dog"){
	Brainz = new Brain();
    std::cout << _type << " default constructor called" << std::endl;
}

Dog::~Dog()
{
	delete Brainz;
	std::cout << _type << " have been destroyed!!!" << std::endl;
}

Dog &Dog::operator=(const Dog &original)
{
	_type = original._type;
	Brainz = new Brain(*original.Brainz); //copy
	std::cout << _type +  " copy done." << std::endl;
	return (*this);
}

void Dog::makeSound()const{
	std::cout << "Ti dico bau" << std::endl;
	system("afplay sound/dog.mp3");
}

void Dog:: setIdeas(std::string str, int i) const
{
	std::cout << "setting ideas" << std::endl;
	Brainz->Ideas[i] = str;
	
}

std::string	Dog::getIdea(int i) const
{
	return (Brainz->Ideas[i]);
}