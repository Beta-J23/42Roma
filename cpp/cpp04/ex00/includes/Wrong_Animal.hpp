/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wrong_Animal.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:01:27 by alpelliz          #+#    #+#             */
/*   Updated: 2024/01/21 17:25:08 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>
#include "Animal.hpp"

class Wrong_Animal {
	protected:
		std::string _type;
	public:
		Wrong_Animal();
		Wrong_Animal(std::string type);
		~Wrong_Animal();
		
		void makeSound()const;
		std::string getType() const;
};

#endif