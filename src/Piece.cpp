#include "../include/Piece.hh"

Piece::~Piece(){
}

void Piece::set_id(int x){
	this->id = x;
}

void Piece::set_position(sf::Vector2i dest){
	this->position = dest;
	this->piece.setPosition(sf::Vector2f(1+17*2*dest.x, 1*17*2*dest.y));
}

void Piece::set_first_move(bool b){
	this->first_move = b;
}

sf::Vector2i Piece::get_position(){
	return position;
}

sf::Sprite Piece::get_sprite(){
	return piece;
}

std::string Piece::get_tex_path(){
	return tex_path;
}

bool Piece::get_enemy(){
	return enemy;
}

std::vector<sf::Vector2i>Piece::get_available_moves(std::vector<sf::Vector2i> ofp, std::vector<sf::Vector2i> pfp){
	std::vector<sf::Vector2i> t = {sf::Vector2i(0,0)};
	return t;
}

int Piece::get_id(){
	return id;
}

int Piece::get_cost(){
	return cost;
}

bool Piece::is_captured(){
	return captured;
}

void Piece::capture(){
	this->captured = true;
}
