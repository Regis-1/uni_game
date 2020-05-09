#ifndef MANAGER_HH
#define MANAGER_HH

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "../include/Drawer.hh"
#include "../include/Piece.hh"
#include "../include/Pawn.hh"

class Manager{
	private:
		Drawer drawer;

		sf::Vector2f size;
		sf::RenderWindow window;
		sf::Event event;

		Piece *p_piece = NULL;
		Pawn pawn; 

		int handle_events(sf::Event event);
	public:
		Manager(float dim_x, float dim_y, std::string title);
		int run();
		int close();

};

#endif
