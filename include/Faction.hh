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
		Pawn *pawns[8];
		Bishop *bishops[2];
		Knight *knights[2];
		Rook *rooks[2];
		Queen *queen;
		King *king;

		void after_move(sf::Vector2i pos, Faction *opponent_faction);
	public:
		Faction(){}
		Faction(Team t, bool enemy=false);
		Piece *get_piece_by_pos(sf::Vector2i pos);
		std::vector<sf::Vector2i> get_faction_pos();	
		std::vector<Piece *> get_all_pieces();
		bool move_piece(Piece *piece, sf::Vector2i pos, Faction *opponent_faction);
		void kill_piece(int id);
};

#endif
