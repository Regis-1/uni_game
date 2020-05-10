#include "../include/Rook.hh"

Rook::Rook(Team team, sf::Vector2i pos, bool enemy){
	this->position = pos;
	this->team = team;
	this->enemy = enemy;

	this->piece.setPosition(sf::Vector2f(1+17*2*pos.x, 1+17*2*pos.y));
	
	if(team == Team::blue)
		this->tex_path = this->tex_path+"rookB.png";
	else
		this->tex_path = this->tex_path+"rookY.png";
}
