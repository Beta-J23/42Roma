/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:01:32 by alpelliz          #+#    #+#             */
/*   Updated: 2024/01/22 11:58:33 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Brain.hpp"
#include "Animal.hpp"

class Dog:public Animal{
	private:
		Brain *Brainz;
	public:
		Dog();
		~Dog();
		
		void makeSound() const;
		void		setIdeas(std::string str, int i) const;
		std::string	getIdea(int n) const; 
};

#endif