#ifndef PIECE_HH
#define PIECE_HH

#include <iostream>
#include <string>
#include <cstdlib>
#include <SFML/Graphics.hpp>

enum Team{
	blue,
	yellow
};

class Piece{
	protected:
		std::string tex_path = "res/";
		sf::Vector2i position;
		sf::Sprite piece;
		int id;
		Team team;
		bool enemy;
		int cost;
		bool first_move = true;

	public:
		void set_id(int x);
		void set_position(sf::Vector2i dest);
		sf::Vector2i get_position();
		sf::Sprite get_sprite();
		sf::Texture get_texture();
		std::string get_tex_path();
		bool get_enemy();
		virtual bool check_move(sf::Vector2i dest){return false;}
};

#endif
