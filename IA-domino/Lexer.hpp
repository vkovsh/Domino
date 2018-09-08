/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-blev <lle-blev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 09:45:37 by lle-blev          #+#    #+#             */
/*   Updated: 2015/11/26 10:22:02 by lle-blev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_HPP
# define LEXER_HPP

# include <regex>

class Lexer {

	public:
		Lexer();
		~Lexer();

		int			readEntries( std::string entry );

	private:
		std::vector<std::regex>		_regex_entries;
};

#endif