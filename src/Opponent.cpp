#include "../include/Opponent.hh"

Opponent::Opponent(Faction *opponent_f, Faction *player_f){
	this->player_faction = player_f;
	this->opponent_faction = opponent_f;

	std::cout<<"Opponent has been initialized."<<std::endl;
}

void Opponent::make_move(){
	std::cout<<"Opponent made move..."<<std::endl;
}
