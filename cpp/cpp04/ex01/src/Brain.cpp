/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:19:00 by alpelliz          #+#    #+#             */
/*   Updated: 2024/01/22 13:37:57 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain(){
    std::cout << "Brain Default constructor called" << std::endl;
}

Brain::~Brain(){
    std::cout << "Brain Destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &assign)
{
	if (this != &assign)
	{
		for (int i = 0; i < 100; i++)
			Ideas[i] = assign.Ideas[i];
	} //Ideas è un array di oggetti string, per questo sono da copiarli singolarmente
	std::cout << "Brain operator called." << std::endl;
	return (*this);
}
