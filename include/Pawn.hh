#ifndef PAWN_HH
#define PAWN_HH

#include "../include/Piece.hh"

class Pawn : public Piece{
	public:
		Pawn(){}
		Pawn(Team team, sf::Vector2i pos, bool enemy=false);
		bool check_move(sf::Vector2i dest);
};

#endif
