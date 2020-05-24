#ifndef AITREE_HH
#define AITREE_HH

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <SFML/Graphics.hpp>

#include "../include/Faction.hh"

class AiTree{
	private:
		bool maximising_player = false;
		int depth;
		std::vector<std::unique_ptr<AiTree>> children;
		
		bool root = true;
		sf::Vector2i local_move;
		Piece *local_piece;

		int alpha;
		int beta;
		const int infinity = 2147483647;

		Faction *opponent_faction;
		Faction *player_faction;
	public:
		AiTree(){};
		AiTree(int dep, Faction opponent_f, Faction player_f);
		AiTree(Piece *piece, sf::Vector2i move, bool maximising, int alp, int bet, int dep, Faction opponent_f, Faction player_f);
		~AiTree();
		void insert_child(Piece *piece, sf::Vector2i move, bool maximising, int alp, int bet);
		int evaluate();
		sf::Vector2i get_local_move(){return local_move;}
		Piece *get_local_piece(){return local_piece;}
};

#endif
