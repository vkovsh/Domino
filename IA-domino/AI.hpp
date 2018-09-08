/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AI.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-blev <lle-blev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 15:23:29 by lle-blev          #+#    #+#             */
/*   Updated: 2015/11/26 11:09:03 by lle-blev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AI_HPP
# define AI_HPP

# include <vector>
# include <list>
# include "Domino.hpp"

class AI {

	public:
		AI();
		~AI();

		void						chooseAction( int action, std::string token );
		typedef void				(AI::*actionsPtr)( std::string );
		void						definePlayerNumber( std::string token );
		void						defineBoard( std::string token );
		void						receivePieces( std::string token );
		void						play( std::string token );
		void						newPieceOnBoard( std::string token );
		void						registerEnd( std::string token );
		void						registerOtherPlayerAction( std::string token );

		void						createNewPlayerStack( int player_nb );
		bool						isEnd( void );

	private:
		/* GAME INFO */
		unsigned int							_col;
		unsigned int							_line;
		unsigned int							_extremities;
		std::list< Domino >						_dominos_on_board;
		std::vector< std::pair<int, int> >		_others_players_stack;
		int										_base_game;
		/* PLAYER INFO */
		unsigned int							_player_number;
		std::vector< std::pair< int, int > >	_stack;
		/* GENERAL */
		static actionsPtr						_actions[7];
		bool									_is_end;

	};

#endif