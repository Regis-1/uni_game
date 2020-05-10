#ifndef FACTION_HH
#define FACTION_HH

#include "../include/Piece.hh"
#include "../include/Pawn.hh"
#include "../include/Bishop.hh"
#include "../include/Knight.hh"
#include "../include/Rook.hh"
#include "../include/Queen.hh"
#include "../include/King.hh"

class Faction{
	private:
		Pawn pawns[8];
		Bishop bishops[2];
		Knight knights[2];
		Rook rooks[2];
		Queen queen;
		King king;
	public:
		Faction(){}
		Faction(Team t, bool enemy=false);
		Pawn *get_pawns(){return pawns;}
		Bishop *get_bishops(){return bishops;}
		Knight *get_knights(){return knights;}
		Rook *get_rooks(){return rooks;}
		Queen get_queen(){return queen;}
		King get_king(){return king;}
		Piece *get_piece_by_pos(sf::Vector2i pos);
};

#endif
