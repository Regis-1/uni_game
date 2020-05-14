#ifndef STATS_HH
#define STATS_HH

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class Stats{
	private:
		std::string players[2];
		int **piece_counter = new int* [2];
		sf::Color counter_colors[5] = {sf::Color(237,0,140), sf::Color(246,148,29), sf::Color(237,224,31), sf::Color(87,183,93), sf::Color(43,194,239)};
		std::string icons_names[5] = {"pawn", "bishop", "knight", "rook", "queen"};
		sf::Vector2f **icons_pos = new sf::Vector2f* [2];
	public:
		Stats();
		std::string *get_players();
		std::string *get_icons_names();
		sf::Vector2f **get_icons_pos();
		int **get_piece_counter();
		sf::Color *get_counter_colors();
};

#endif
