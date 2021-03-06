#ifndef MANAGER_HH
#define MANAGER_HH

#include <string>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <thread>
#include <SFML/Graphics.hpp>

#include "../include/Drawer.hh"
#include "../include/AudioPlayer.hh"
#include "../include/Stats.hh"
#include "../include/Opponent.hh"
#include "../include/AiTree.hh"

class Manager{
	private:
		Drawer drawer;
		sf::Vector2i size;
		sf::RenderWindow window;
		sf::Event event;
		GameState g_state;

		Faction *player_faction;
		Faction *opponent_faction;
		Opponent opponent;

		Stats *stats;
		AudioPlayer *audio_player;
		bool active_player = false;

		bool second_click = false;
		Piece *p_selected = NULL;

		int handle_events(sf::Event event);
		sf::Vector2i get_mouse_tile();
		void click_on_board(sf::Event event);
		void click_on_menu(sf::Event event);
		void refresh_screen();
		void title_rollup();
	public:
		Manager(int dim_x, int dim_y, std::string title, int dep);
		~Manager();
		int run();
		int close();
};

#endif
