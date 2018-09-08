/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tools.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-blev <lle-blev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 15:44:56 by lle-blev          #+#    #+#             */
/*   Updated: 2015/11/10 15:57:05 by lle-blev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tools.hpp"

std::vector<std::string>			explode(const std::string & str, char delimit) {

	std::istringstream			split(str);
	std::vector<std::string>	tokens;

	for (std::string each; std::getline(split, each, delimit); tokens.push_back(each));
	return (tokens);
}

bool								str_isdigit(std::string token) {

	for (size_t i  = 0; i < token.size(); ++i)
	{
		if (!isdigit(token[i]))
			return false;
	}
	return true;
}
