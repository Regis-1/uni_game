#ifndef KING_HH
#define KING_HH

#include "../include/Piece.hh"

class King : public Piece{
	public:
		King(){}
		King(Team team, sf::Vector2i pos, bool enemy=false);
		bool check_move(sf::Vector2i dest);
};

#endif
