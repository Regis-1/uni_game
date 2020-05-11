#ifndef BISHOP_HH
#define BISHOP_HH

#include "../include/Piece.hh"

class Bishop : public Piece{
	public:
		Bishop(){}
		Bishop(Team team, sf::Vector2i pos, bool enemy=false);
		bool check_move(sf::Vector2i dest);
};

#endif
