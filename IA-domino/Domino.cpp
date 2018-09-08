/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Domino.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-blev <lle-blev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 15:23:29 by lle-blev          #+#    #+#             */
/*   Updated: 2015/11/26 10:22:03 by lle-blev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Domino.hpp"

Domino::Domino() { }

Domino::Domino(std::pair<unsigned int, unsigned int> domino, std::pair<unsigned int, unsigned int> position, unsigned int orientation)
				: _value(domino), _position(position), _orientation(orientation) {

}

Domino::~Domino() { }

std::pair<unsigned int, unsigned int>		Domino::getValue(void) const {

	return this->_value;
}
std::pair<unsigned int, unsigned int>		Domino::getPosition(void) const {

	return this->_position;
}
unsigned int								Domino::getOrientation(void) const {

	return this->_orientation;
}
bool										Domino::getUp(void) const {

	return this->_up;
}
bool										Domino::getDown(void) const {

	return this->_down;
}
bool										Domino::getLeft(void) const {

	return this->_left;
}
bool										Domino::getRight(void) const {

	return this->_right;
}
bool										Domino::isDouble(void) {

	return (this->_value.first == this->_value.second ? true : false);
}