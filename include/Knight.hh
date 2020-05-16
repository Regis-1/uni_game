#ifndef KNIGHT_HH
#define KNIGHT_HH

#include "../include/Piece.hh"

class Knight : public Piece{
	public:
		Knight(){}
		Knight(Team team, sf::Vector2i pos, bool enemy=false, int id=0);
		std::vector<sf::Vector2i> get_available_moves(std::vector<sf::Vector2i> ofp, std::vector<sf::Vector2i> pfp);
};

#endif
