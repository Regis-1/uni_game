#include "../include/Stats.hh"

Stats::Stats(){
	players[0] = "player";
	players[1] = "opponent";
	for(int i=0; i<2; i++){
		icons_pos[i] = new sf::Vector2f [5];
		piece_counter[i] = new int [5];
		for(int j=0; j<5; j++){
			piece_counter[i][j] = 0;
			if(i==0)
				icons_pos[i][j] = sf::Vector2f(295+16*j, 135);
			else
				icons_pos[i][j] = sf::Vector2f(295+16*j, 205);
		}
	}

	std::cout<<"Stats created!"<<std::endl;
}

std::string *Stats::get_players(){
	return this->players;
}

std::string *Stats::get_icons_names(){
	return this->icons_names;
}

sf::Vector2f **Stats::get_icons_pos(){
	return this->icons_pos;
}

int **Stats::get_piece_counter(){
	return this->piece_counter;
}

sf::Color *Stats::get_counter_colors(){
	return this->counter_colors;
}
