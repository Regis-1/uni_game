#ifndef QUEEN_HH
#define QUEEN_HH

#include "../include/Piece.hh"

class Queen : public Piece{
	public:
		Queen(){}
		Queen(Team team, sf::Vector2i pos, bool enemy=false);
};

#endif
