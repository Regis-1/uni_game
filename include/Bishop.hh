#ifndef BISHOP_HH
#define BISHOP_HH

#include "../include/Piece.hh"

class Bishop : public Piece{
	public:
		Bishop(){}
		Bishop(Team team, sf::Vector2i pos, bool enemy=false, int id=0);
		std::vector<sf::Vector2i> get_available_moves(std::vector<sf::Vector2i> ofp, std::vector<sf::Vector2i> pfp);
};

#endif
