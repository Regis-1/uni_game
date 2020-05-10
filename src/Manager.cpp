#include "../include/Manager.hh"

Manager::Manager(int dim_x, int dim_y, std::string title){
	window.create(sf::VideoMode(dim_x, dim_y), title);
	drawer = Drawer("Lazer84.ttf");
	size.x = dim_x;
	size.y = dim_y;

	/*for(int i=0; i<NPAWNS/2; i++)
		pawn[i] = Pawn(Team::blue, sf::Vector2f(i,6));
	for(int i=0; i<NPAWNS/2; i++)
		pawn[(NPAWNS/2) + i] = Pawn(Team::yellow, sf::Vector2f(i, 1), true);*/
}

int Manager::run(){
	sf::Vector2i mouse_tile;

	std::cout<<"Starting the game..."<<std::endl;
	
	//game loop
	while(window.isOpen()){
		
		while(window.pollEvent(event)){
			handle_events(event);
		}

		mouse_tile = get_mouse_tile(&window);

		window.clear();
		/* visible part */
		drawer.draw_board(&window);
		/*for(int i=0; i<NPAWNS; i++){
			p_piece = &pawn[i];
			drawer.draw_piece(&window, p_piece);
		}*/
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

sf::Vector2i Manager::get_mouse_tile(sf::RenderWindow *win){
	sf::Vector2i tile;
	sf::Vector2i l_pos = sf::Mouse::getPosition(*win);
	bool found = false;

	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			if(l_pos.x>1+17*2*j && l_pos.x<(1+j)*17*2 &&
				 l_pos.y>1+17*2*i && l_pos.y<(1+i)*17*2){
				tile = sf::Vector2i(j,i);
				found = true;
				break;
			}
			else
				tile = sf::Vector2i(-1,-1);
		}
		if(found)
			break;
	}
	
	return tile;
}
