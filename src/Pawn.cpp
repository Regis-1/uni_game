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

bool Pawn::check_move(sf::Vector2i dest){
	sf::Vector2i move_vec = position - dest;
	if(move_vec.y == 2 && first_move){
		first_move = false;
		return true;
	}
	else if(move_vec.y == 1){
		if(first_move)
			first_move = false;
		return true;
	}
	else
		return false;
}
