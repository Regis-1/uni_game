#ifndef MANAGER_HH
#define MANAGER_HH

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "../include/Drawer.hh"
#include "../include/Piece.hh"
#include "../include/Pawn.hh"

#define NPAWNS 16

class Manager{
	private:
		Drawer drawer;

		sf::Vector2i size;
		sf::RenderWindow window;
		sf::Event event;

		Piece *p_piece = NULL;

		int handle_events(sf::Event event);
		sf::Vector2i get_mouse_tile(sf::RenderWindow *win);
	public:
		Manager(int dim_x, int dim_y, std::string title);
		int run();
		int close();

};

#endif
