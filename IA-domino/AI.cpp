/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AI.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-blev <lle-blev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/20 15:50:39 by lle-blev          #+#    #+#             */
/*   Updated: 2015/11/26 15:35:52 by lle-blev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AI.hpp"
#include "Tools.hpp"

AI::AI()
		: _col(0), _line(0), _extremities(0), _base_game(0), _player_number(0), _is_end(false) {

}

AI::~AI() { }

void				AI::chooseAction( int action, std::string token ) {

	(this->*_actions[action])(token);
}

AI::actionsPtr		AI::_actions[7] = {
	&AI::definePlayerNumber,
	&AI::defineBoard,
	&AI::receivePieces,
	&AI::play,
	&AI::newPieceOnBoard,
	&AI::registerEnd,
	&AI::registerOtherPlayerAction
};

void				AI::definePlayerNumber( std::string token ) {

	//std::cout << "definePlayerNumber = " << token << std::endl;
	//std::cout << token << std::endl;
	std::vector< std::string>	tokens = explode(token, ':');

	if (tokens.size() == 3 && str_isdigit(tokens[2]))
		this->_player_number = atoi(tokens[2].c_str());
}
void				AI::defineBoard( std::string token ) {

	//std::cout << "defineBoard = " << token << std::endl;
	std::vector< std::string>	tokens = explode(token, ':');

	if (tokens.size() == 3 && str_isdigit(tokens[1]) && str_isdigit(tokens[2]))
	{
		this->_col = atoi(tokens[1].c_str());
		this->_line = atoi(tokens[2].c_str());
	}
}
void				AI::receivePieces( std::string token ) {

	//std::cout << "receivePieces = " << token << std::endl;
	int							nb_pieces;
	std::vector< std::string>	tokens = explode(token, ':');
	std::string					line;

	if (tokens.size() == 3 && str_isdigit(tokens[2]))
	{
		nb_pieces = atoi(tokens[2].c_str());
		if (!this->_base_game)
			_base_game = nb_pieces;
		for (int i = 0; i < nb_pieces; ++i)
		{
			std::getline (std::cin, line);
			tokens = explode(line, ':');
			if (tokens.size() == 3 && str_isdigit(tokens[1]) && str_isdigit(tokens[2]))
			{
				std::pair<int, int>		domino = std::pair<int, int>(atoi(tokens[1].c_str()), atoi(tokens[2].c_str()));
				this->_stack.push_back(domino);
			}
		}
	}
}
void				AI::play( std::string token ) {

	std::cout << "play = " << token << std::endl;
}
void				AI::newPieceOnBoard( std::string token ) {

	//std::cout << "newPieceOnBoard = " << token << std::endl;
	std::vector< std::string>	tokens;
	std::string					line;

	for (int i = 0; i < 3; ++i)
	{
		std::getline (std::cin, line);
		tokens = explode(line, ':');
		if (tokens.size() == 3 && str_isdigit(tokens[1]) && str_isdigit(tokens[2]))
		{
			std::pair<int, int>		domino = std::pair<int, int>(atoi(tokens[1].c_str()), atoi(tokens[2].c_str()));
			this->_stack.push_back(domino);
		}
	}
	std::cout << this->_extremities << std::endl;

}
void				AI::registerEnd( std::string token ) {

	std::cout << "registerEnd = " << token << std::endl;
	(void)token;
	this->_is_end = true;
}
void				AI::registerOtherPlayerAction( std::string token ) {

	std::cout << "registerOtherPlayerAction = " << token << std::endl;
	std::vector< std::string>	tokens = explode(token, ':');
	std::pair<int, int>			pair;
	bool						playerFound = false;
	int							player_nb;

	if (tokens.size() == 3 && atoi(tokens[1].c_str()) != this->_player_number)
	{
		player_nb = atoi(tokens[1].c_str());
		for (size_t i = 0; i < this->_others_players_stack.size() && this->_player_number != player_nb; ++i)
			if (this->_others_players_stack[i].first == player_nb)
				playerFound = true;
		if (!playerFound)
			this->createNewPlayerStack(player_nb);
		for (size_t i = 0; i < this->_others_players_stack.size(); ++i)
		{
			if (this->_others_players_stack[i].first == player_nb)
			{
				if (tokens[2] == "put")
					this->_others_players_stack[i].second--;
				if (tokens[2] == "draw")
					this->_others_players_stack[i].second++;
			}
		}
	}
}
void				AI::createNewPlayerStack( int player_nb ) {

	std::pair<int, int>			pair;

	pair.first = player_nb;
	pair.first = this->_base_game;
	this->_others_players_stack.push_back(pair);
}

bool				AI::isEnd( void ) {

	return this->_is_end;
}