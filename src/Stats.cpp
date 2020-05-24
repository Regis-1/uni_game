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

Stats::~Stats(){
	delete [] piece_counter;
	delete [] icons_pos;
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

//UPDATING THE STATS [CAPTURED PIECES COUNTERS ETC]
void Stats::update_stats(Faction *player_faction, Faction *opponent_faction){
	std::vector<Piece *> pieces = opponent_faction->get_all_pieces();
	int n[5] = {0};

	for(int i=0; i<2; i++){
		for(int j=0; j<16; j++)
			if(pieces[j] == NULL){
				if(j<8)
					n[0]++;
				else if(j>=8 && j<10)
					n[1]++;
				else if(j>=10 && j<12)
					n[2]++;
				else if(j>=12 && j<14)
					n[3]++;
				else if(j==14)
					n[4]++;
			}

		for(int j=0; j<5; j++)
			piece_counter[i][j] = n[j];
		n[0]=0; n[1]=0; n[2]=0; n[3]=0; n[4]=0;
		pieces = player_faction->get_all_pieces();
	}
}
