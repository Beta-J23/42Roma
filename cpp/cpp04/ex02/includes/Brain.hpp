/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:18:45 by alpelliz          #+#    #+#             */
/*   Updated: 2024/01/22 11:33:28 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Animal.hpp"

class Brain {
	private:
	public:
		Brain();
		~Brain();
		std::string Ideas[99];
		//Brain(const Brain &original);

		Brain &operator=(const Brain &assign);
		//void set_Ideas();
};

#endif

