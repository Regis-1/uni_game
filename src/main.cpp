#include <SFML/Graphics.hpp>
#include <iostream>

#include "../include/Manager.hh"

int main(int argc, char *argv[]){
	const int dim_x = 404;
	const int dim_y = 274;
	const std::string title = "knight rider";

	Manager game(dim_x, dim_y, title);

	game.run();

	std::cout<<"Program finished!"<<std::endl;
	return 0;
}
