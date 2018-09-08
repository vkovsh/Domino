/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Domino.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-blev <lle-blev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 15:23:29 by lle-blev          #+#    #+#             */
/*   Updated: 2015/11/20 15:48:51 by lle-blev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOMINO_HPP
# define DOMINO_HPP

# include <vector>

class Domino {

	public:
		Domino();
		Domino(std::pair<unsigned int, unsigned int> domino, std::pair<unsigned int, unsigned int> position, unsigned int orientation);
		~Domino();

		std::pair<unsigned int, unsigned int>	getValue(void) const;
		std::pair<unsigned int, unsigned int>	getPosition(void) const;
		unsigned int							getOrientation(void) const;
		bool									getUp(void) const;
		bool									getDown(void) const;
		bool									getLeft(void) const;
		bool									getRight(void) const;

		bool									isDouble(void);

	private:
		std::pair<unsigned int, unsigned int>	_value;
		std::pair<unsigned int, unsigned int>	_position;
		unsigned int							_orientation;
		bool									_up;
		bool									_down;
		bool									_left;
		bool									_right;

};

#endif