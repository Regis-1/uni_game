#include <SFML/Graphics.hpp>
#include <iostream>

#include "../include/Manager.hh"

int main(int argc, char *argv[]){
	const int dim_x = 404;
	const int dim_y = 274;
	const std::string title = "knight rider";
	int depth = 0;

	std::cout<<"Welcome in KNIGHT_RIDER"<<std::endl<<std::endl;
	std::cout<<"How many steps the opponent will be ahead of You?"<<std::endl;
	std::cout<<": ";
	std::cin>>depth;
	std::cout<<std::endl;

	if(!std::cin.good()){
		std::cout<<"Not a number!"<<std::endl;
		return -1;
	}

	Manager *game = new Manager(dim_x, dim_y, title, depth);

	game->run();

	delete game;

	std::cout<<"Program finished!"<<std::endl;
	return 0;
}
