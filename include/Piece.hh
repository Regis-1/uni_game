#ifndef PIECE_HH
#define PIECE_HH

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
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
		virtual ~Piece();
		void set_id(int x);
		void set_position(sf::Vector2i dest);
		void set_first_move(bool b);
		sf::Vector2i get_position();
		sf::Sprite get_sprite();
		sf::Texture get_texture();
		std::string get_tex_path();
		bool get_enemy();
		virtual std::vector<sf::Vector2i> get_available_moves(std::vector<sf::Vector2i> ofp, std::vector<sf::Vector2i> pfp);
		int get_id();
};

#endif
