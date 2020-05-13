#ifndef DRAWER_HH
#define DRAWER_HH

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/Piece.hh"
#include "../include/Faction.hh"
#include "../include/AudioPlayer.hh"
#include "../include/Stats.hh"

class Drawer{
	private:
		sf::Font font;
		sf::Texture board_tex;
	public:
		Drawer(){};
		Drawer(std::string font_file);
		void draw_text(sf::RenderWindow *win, sf::Vector2f pos, std::string content, int size = 16, sf::Color color = sf::Color(161,44,177));
		void draw_board(sf::RenderWindow *win);
		void draw_line(sf::RenderWindow *win, sf::Vector2f p1, sf::Vector2f p2, sf::Color color = sf::Color::White);
		void draw_piece(sf::RenderWindow *win, Piece *piece);
		void draw_faction(sf::RenderWindow *win, Faction *f);
		void draw_audioplayer(sf::RenderWindow *win, AudioPlayer *a);
		void draw_stats(sf::RenderWindow *win, Stats *s);
};

#endif
