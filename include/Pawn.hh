#ifndef PAWN_HH
#define PAWN_HH

#include "../include/Piece.hh"

class Pawn : public Piece{
	public:
		Pawn(){}
		Pawn(Team team, sf::Vector2i pos, bool enemy=false, int id=0);
		std::vector<sf::Vector2i> get_available_moves(std::vector<sf::Vector2i> ofp, std::vector<sf::Vector2i> pfp);
};

#endif
