#ifndef OPPONENT_HH
#define OPPONENT_HH

#include <vector>
#include <iostream>

#include <ctime>
#include <cstdlib>

#include <SFML/Graphics.hpp>

#include "../include/AiTree.hh"

class Opponent{
	private:
		Faction *player_faction;
		Faction *opponent_faction;

		AiTree *ai;
		int depth;

	public:
		Opponent(){}
		Opponent(Faction *opponent_f, Faction *player_f, int dep=2);
		GameState make_move();
};

#endif
