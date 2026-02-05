/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:47:08 by alpelliz          #+#    #+#             */
/*   Updated: 2024/01/18 16:09:21 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private:
		std::string _name;
	public:
		Zombie();
		Zombie(std::string zombie_name);
		~Zombie();
		//void set_name(std::string str);
		//std::string get_name(void);
		void announce(void);
		Zombie* newZombie(std::string name);
		void randomChump( std::string name );
};


#endif
