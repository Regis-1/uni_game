#include "../include/Stats.hh"

Stats::Stats(){
	players[0] = "player";
	players[1] = "opponent";
	for(int i=0; i<2; i++)
		for(int j=0; j<5; j++){
			piece_activator[i][j] = false;
			piece_counter[i][j] = 0;
		}

	std::cout<<"Stats created!"<<std::endl;
}

std::string *Stats::get_players(){
	return this->players;
}
