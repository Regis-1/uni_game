#ifndef OPPONENT_HH
#define OPPONENT_HH

#include <vector>
#include <iostream>

//For rand moves...
#include <ctime>
#include <cstdlib>

#include <SFML/Graphics.hpp>

#include "../include/Faction.hh"

class Opponent{
	private:
		Faction *player_faction;
		Faction *opponent_faction;
	public:
		Opponent(){}
		Opponent(Faction *opponent_f, Faction *player_f);
		void make_move();
};

#endif
