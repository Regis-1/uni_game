#ifndef FACTION_HH
#define FACTION_HH

#include "../include/Piece.hh"
#include "../include/Pawn.hh"
#include "../include/Bishop.hh"
#include "../include/Knight.hh"
#include "../include/Rook.hh"
#include "../include/Queen.hh"
#include "../include/King.hh"

enum GameState{
	player_move,
	opponent_move,
	player_check,
	opponent_check,
	player_mate,
	opponent_mate
};

class Faction{
	private:
		Pawn *pawns[8];
		Bishop *bishops[2];
		Knight *knights[2];
		Rook *rooks[2];
		Queen *queen;
		King *king;

		int id_of_killed;
		bool killed = false;
		Piece *moved_piece;
		sf::Vector2i last_pos;

		void after_move(sf::Vector2i pos, Faction *opponent_faction);
		GameState is_check(Faction *opponent_faction);
	public:
		Faction(){}
		Faction(Team t, bool enemy=false);
		~Faction();
		Faction(const Faction &F);
		Piece *get_piece_by_pos(sf::Vector2i pos);
		Piece *get_piece_by_id(int id);
		std::vector<sf::Vector2i> get_faction_pos();	
		std::vector<Piece *> get_all_pieces();
		GameState move_piece(Piece *piece, sf::Vector2i pos, Faction *opponent_faction);
		void capture_piece(int id, bool kill=true);
		void revive_piece(int id);
		void print_padd();
		int calculate_value();
		void undo_move(Faction *opponent_f);

		Pawn get_pawn(int i) const;
		Bishop get_bishop(int i) const;
		Knight get_knight(int i) const;
		Rook get_rook(int i) const;
		Queen get_queen() const;
		King get_king() const;
};

#endif
