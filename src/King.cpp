#include "../include/King.hh"

King::King(Team team, sf::Vector2i pos, bool enemy){
	this->position = pos;
	this->team = team;
	this->enemy = enemy;

	this->piece.setPosition(sf::Vector2f(1+17*2*pos.x, 1+17*2*pos.y));
	
	if(team == Team::blue)
		this->tex_path = this->tex_path+"kingB.png";
	else
		this->tex_path = this->tex_path+"kingY.png";
}

bool King::check_move(sf::Vector2i dest){
	sf::Vector2i move_vec = position - dest;
	move_vec = sf::Vector2i(std::abs(move_vec.x), std::abs(move_vec.y));
	if(move_vec.x < 2 && move_vec.y < 2)
		return true;
	else
		return false;
}
