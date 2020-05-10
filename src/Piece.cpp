#include "../include/Piece.hh"

void Piece::set_id(int x){
	this->id = x;
}

void Piece::set_position(sf::Vector2i dest){
	this->position = dest;
	this->piece.setPosition(sf::Vector2f(1+17*2*dest.x, 1*17*2*dest.y));
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
