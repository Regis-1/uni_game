#ifndef OPPONENT_HH
#define OPPONENT_HH

#include <vector>
#include <iostream>

#include <ctime>
#include <cstdlib>

#include <SFML/Graphics.hpp>

#include "../include/Tree.hh"
#include "../include/Faction.hh"

class Opponent{
	private:
		Faction *player_faction;
		Faction *opponent_faction;

		Tree *moves_tree;
	public:
		Opponent(){}
		Opponent(Faction *opponent_f, Faction *player_f);
		GameState make_move();
};

#endif
