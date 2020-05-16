#ifndef ROOK_HH
#define ROOK_HH

#include "../include/Piece.hh"

class Rook : public Piece{
	public:
		Rook(){}
		Rook(Team team, sf::Vector2i pos, bool enemy=false);
		std::vector<sf::Vector2i> get_available_moves(std::vector<sf::Vector2i> ofp, std::vector<sf::Vector2i> pfp);
};

#endif
