#include "../include/Piece.hh"

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
