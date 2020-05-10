#ifndef ROOK_HH
#define ROOK_HH

#include "../include/Piece.hh"

class Rook : public Piece{
	public:
		Rook(){}
		Rook(Team team, sf::Vector2i pos, bool enemy=false);
};

#endif
