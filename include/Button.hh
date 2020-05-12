#ifndef BUTTON_HH
#define BUTTON_HH

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

enum ButtonState{
	inactive,
	active
};

class Button{
	private:
		sf::Sprite sprite;
		sf::Vector2i position;
		std::string btn_name;
		ButtonState state = inactive;
	public:
		Button(){}
		Button(std::string btn_name, sf::Vector2i pos);
		void set_state(ButtonState bs);
		std::string get_btn_tex_path();
		sf::Sprite get_sprite();
};

#endif
