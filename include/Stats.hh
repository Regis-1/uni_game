#ifndef STATS_HH
#define STATS_HH

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class Stats{
	private:
		std::string players[2];
		bool piece_activator[2][5];
		int piece_counter[2][5];
		//sf::Sprite piece_icons;
	public:
		Stats();
		std::string *get_players();
};

#endif
