#ifndef PAWN_HH
#define PAWN_HH

#include "../include/Piece.hh"

class Pawn : public Piece{
	public:
		Pawn(){}
		Pawn(Team team, sf::Vector2f pos, bool enemy=false);
};

#endif
