/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:09:55 by alpelliz          #+#    #+#             */
/*   Updated: 2024/01/19 15:47:10 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanB{
	private:
		//Weapon _weapon;
		Weapon *_weapon;
		std::string _name;
	public:
	HumanB();
	HumanB(std::string name);
	~HumanB();
	void setWeapon(Weapon &weap);
	std::string getname();
	void setname(std::string name);
	void attack();
};