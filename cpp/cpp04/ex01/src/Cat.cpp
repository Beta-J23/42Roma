/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:01:40 by alpelliz          #+#    #+#             */
/*   Updated: 2024/01/22 14:00:36 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat() : Animal("Cat"){
	Brainz = new Brain();
    std::cout << _type << " default constructor called" << std::endl;
}

Cat::~Cat()
{
	delete Brainz;
	std::cout << _type << " have been destroyed!!!" << std::endl;
}

void Cat::makeSound()const{
	std::cout << "Ti dico miao" << std::endl;
	system("afplay sound/cat.wav");
}

Cat &Cat::operator=(const Cat &assign)
{
	_type = assign._type;
	Brainz = new Brain(*assign.Brainz); //copy
	std::cout << _type +  " copy done." << std::endl;
	return (*this);
}

void	Cat::setIdeas(std::string str, int i) const
{
	Brainz->Ideas[i] = str;
}

std::string	Cat::getIdea(int i) const
{
	return (Brainz->Ideas[i]);
}