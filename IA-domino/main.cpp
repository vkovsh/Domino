/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-blev <lle-blev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 15:23:07 by lle-blev          #+#    #+#             */
/*   Updated: 2015/11/26 11:40:02 by lle-blev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Lexer.hpp"
#include "AI.hpp"

int			main(void) {

	Lexer			lexer;
	AI				ai;
	std::string		line;
	int				action;

	while (!ai.isEnd())
	{
		std::getline (std::cin, line);
		action = lexer.readEntries(line);
		if (action < 7)
			ai.chooseAction(action, line);
	}
	return (0);
}