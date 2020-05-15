#include "../include/Pawn.hh"

Pawn::Pawn(Team team, sf::Vector2i pos, bool enemy){
	this->position = pos;
	this->team = team;
	this->enemy = enemy;

	this->piece.setPosition(sf::Vector2f(1+17*2*pos.x, 1+17*2*pos.y));
	
	if(team == Team::blue)
		this->tex_path = this->tex_path+"pawnB.png";
	else
		this->tex_path = this->tex_path+"pawnY.png";
}

std::vector<sf::Vector2i> Pawn::get_available_moves(){
	std::vector<sf::Vector2i> available_moves;
	if(first_move)
		available_moves.push_back(this->position + sf::Vector2i(0,-2));
	available_moves.push_back(this->position + sf::Vector2i(0,-1));
	return available_moves;
}
