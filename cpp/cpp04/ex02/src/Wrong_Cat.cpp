/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wrong_Cat.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:01:36 by alpelliz          #+#    #+#             */
/*   Updated: 2024/01/21 17:31:54 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Wrong_Cat.hpp"

Wrong_Cat::Wrong_Cat() : Wrong_Animal("Wrong_Cat"){
    std::cout << _type << " default constructor called" << std::endl;
}

Wrong_Cat::~Wrong_Cat()
{
	std::cout << _type << " have been destroyed!!!" << std::endl;
}

void Wrong_Cat::makeSound()const{
	std::cout << "Ti dico miao" << std::endl;
	system("afplay sound/cat.wav");
}
