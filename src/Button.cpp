#include "../include/Button.hh"

Button::Button(std::string btn_name, sf::Vector2i pos){
	this->btn_name = btn_name;
	this->position = pos;

	sprite.setPosition(sf::Vector2f(pos.x, pos.y));
}

void Button::set_state(ButtonState bs){
	this->state = bs;
}

std::string Button::get_btn_tex_path(){
	if(state == ButtonState::inactive){
		return "res/"+btn_name+"0.png";
	}
	else{
		return "res/"+btn_name+"1.png";
	}
}

sf::Sprite Button::get_sprite(){
	return this->sprite;
}
