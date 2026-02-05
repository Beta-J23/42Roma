/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:21:45 by alpelliz          #+#    #+#             */
/*   Updated: 2024/01/20 15:17:52 by alpelliz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed(void) : _fixedPointValue(0) {
    std::cout << "this is Default constructor" << std::endl;
}

Fixed::~Fixed(void) {
    std::cout << "this is Destructor" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
    std::cout << "this is Copy constructor" << std::endl;
    *this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
    std::cout << "this is Assignation operator" << std::endl;
    this->_fixedPointValue = fixed.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const {
    std::cout << "this is getRawBits function" << std::endl;
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}