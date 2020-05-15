#ifndef PAWN_HH
#define PAWN_HH

#include "../include/Piece.hh"

class Pawn : public Piece{
	public:
		Pawn(){}
		Pawn(Team team, sf::Vector2i pos, bool enemy=false);
		std::vector<sf::Vector2i> get_available_moves();
};

#endif
