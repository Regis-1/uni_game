#ifndef QUEEN_HH
#define QUEEN_HH

#include "../include/Piece.hh"

class Queen : public Piece{
	public:
		Queen(){}
		Queen(Team team, sf::Vector2i pos, bool enemy=false);
		std::vector<sf::Vector2i> get_available_moves(std::vector<sf::Vector2i> ofp, std::vector<sf::Vector2i> pfp);
};

#endif
