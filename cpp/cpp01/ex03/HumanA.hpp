/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:08:15 by alpelliz          #+#    #+#             */
/*   Updated: 2024/01/19 15:48:58 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanA{
	private:
		std::string _name;
		Weapon &_weapon;
	public:
	HumanA();
	HumanA(std::string name, Weapon &weptype);
	~HumanA();
	void setname(std::string name);
	std::string getname();
	void attack();
};