/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpelliz <alpelliz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:12:34 by alpelliz          #+#    #+#             */
/*   Updated: 2024/01/20 18:09:00 by alpelliz         ###   ########.fr       */
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

Fixed::Fixed(const int value) {
    std::cout << "this is Int constructor" << std::endl;
    this->_fixedPointValue = value << this->_fractionalBits;
}

Fixed::Fixed(const float value) {
    std::cout << "this is Float constructor" << std::endl;
    this->_fixedPointValue = (int)roundf(value * (1 << this->_fractionalBits));
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

float Fixed::toFloat(void) const {
    return (float)this->_fixedPointValue / (1 << this->_fractionalBits);
}

int Fixed::toInt(void) const {
    return this->_fixedPointValue >> this->_fractionalBits;
}

std::ostream &operator <<(std::ostream &os, const Fixed &obj)
{
    os << obj.toFloat();
    return (os);
}
