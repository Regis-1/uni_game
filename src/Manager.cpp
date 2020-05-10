#include "../include/Manager.hh"

Manager::Manager(float dim_x, float dim_y, std::string title){
	window.create(sf::VideoMode(dim_x, dim_y), title);
	drawer = Drawer("Lazer84.ttf");
	size.x = dim_x;
	size.y = dim_y;

	for(int i=0; i<NPAWNS/2; i++)
		pawn[i] = Pawn(Team::blue, sf::Vector2f(i,6));
	for(int i=0; i<NPAWNS/2; i++)
		pawn[(NPAWNS/2) + i] = Pawn(Team::yellow, sf::Vector2f(i, 1), true);
}

int Manager::run(){
	std::cout<<"Starting the game..."<<std::endl;
	
	//game loop
	while(window.isOpen()){
		
		while(window.pollEvent(event)){
			handle_events(event);
		}

		window.clear();
		/* visible part */
		drawer.draw_board(&window);
		for(int i=0; i<NPAWNS; i++){
			p_piece = &pawn[i];
			drawer.draw_piece(&window, p_piece);
		}
		/* visible part */
		window.display();
	}

	return 0;
}

int Manager::close(){
	std::cout<<"Closing the game..."<<std::endl;
	return 0;
}

/* PRIVATE METHODS */
int Manager::handle_events(sf::Event event){
	if(event.type == sf::Event::Closed)
		window.close();

	return 0;
}
