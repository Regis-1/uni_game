#ifndef KNIGHT_HH
#define KNIGHT_HH

#include "../include/Piece.hh"

class Knight : public Piece{
	public:
		Knight(){}
		Knight(Team team, sf::Vector2i pos, bool enemy=false);
		bool check_move(sf::Vector2i dest);
};

#endif
