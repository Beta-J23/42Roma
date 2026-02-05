/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wrong_Cat.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:01:27 by alpelliz          #+#    #+#             */
/*   Updated: 2024/01/21 17:24:39 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include <iostream>
#include "Wrong_Animal.hpp"

class Wrong_Cat:public Wrong_Animal{
	public:
		Wrong_Cat();
		~Wrong_Cat();
		
		void makeSound() const;
};

#endif