/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-blev <lle-blev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 09:47:28 by lle-blev          #+#    #+#             */
/*   Updated: 2015/11/26 10:36:52 by lle-blev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer.hpp"
#include <iostream>

Lexer::Lexer() {

	std::regex		e;

	e = "(player:n:[0-9]*)";
	this->_regex_entries.push_back(e);
	e = "(board:[0-9]*:[0-9]*)";
	this->_regex_entries.push_back(e);
	e = "(pieces:n:[0-9]*)";
	this->_regex_entries.push_back(e);
	e = "(go)";
	this->_regex_entries.push_back(e);
	e = "(new)";
	this->_regex_entries.push_back(e);
	e = "(end:winner:[0-9]*:score:[0-9]*)";
	this->_regex_entries.push_back(e);
	e = "(p:[0-9]*:put|draw|sulk|ko)";
	this->_regex_entries.push_back(e);
}

Lexer::~Lexer() {

}

int			Lexer::readEntries( std::string entry ) {

	size_t	i;

	for (i = 0; i < this->_regex_entries.size() && !regex_match(entry, this->_regex_entries[i]); ++i);
	//std::cout << "SORS AVEC " << i << std::endl;
	//std::cout << i << std::endl;;
	;
	return i;
}