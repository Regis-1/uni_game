#include "../include/Knight.hh"

Knight::Knight(Team team, sf::Vector2i pos, bool enemy){
	this->position = pos;
	this->team = team;
	this->enemy = enemy;

	this->piece.setPosition(sf::Vector2f(1+17*2*pos.x, 1+17*2*pos.y));

	if(team == Team::blue)
		this->tex_path = this->tex_path+"knightB.png";
	else
		this->tex_path = this->tex_path+"knightY.png";
}
