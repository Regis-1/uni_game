#ifndef KING_HH
#define KING_HH

#include "../include/Piece.hh"

class King : public Piece{
	public:
		King(){}
		King(Team team, sf::Vector2i pos, bool enemy=false);
		std::vector<sf::Vector2i> get_available_moves(std::vector<sf::Vector2i> ofp, std::vector<sf::Vector2i> pfp);
};

#endif
