#include <SFML/Graphics.hpp>
#include <iostream>

#include "../include/Manager.hh"

int main(int argc, char *argv[]){
	const float dim_x = 404.f;
	const float dim_y = 274.f;
	const std::string title = "knight rider";

	Manager game(dim_x, dim_y, title);

	game.run();

	std::cout<<"Program finished!"<<std::endl;
	return 0;
}
