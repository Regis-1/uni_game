#include "../include/Pawn.hh"

Pawn::Pawn(Team team, sf::Vector2f pos, bool enemy){
	this->position = pos;
	this->team = team;

	this->piece.setPosition(sf::Vector2f(1+17*2*pos.x, 1+17*2*pos.y));
	
	if(team == Team::blue)
		this->tex_path = this->tex_path+"pawnB.png";
	else
		this->tex_path = this->tex_path+"pawnY.png";

	this->piece.setScale(2.f, 2.f);

	if(enemy)
		this->piece.rotate(90.f);
}
