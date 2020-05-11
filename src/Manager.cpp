#include "../include/Manager.hh"

Manager::Manager(int dim_x, int dim_y, std::string title){
	window.create(sf::VideoMode(dim_x, dim_y), title, sf::Style::Titlebar | sf::Style::Close);
	drawer = Drawer("Lazer84.ttf");
	size.x = dim_x;
	size.y = dim_y;

	std::cout<<"Starting creating factions..."<<std::endl;
	player_faction = Faction(Team::blue);
	opponent_faction = Faction(Team::yellow, true);
	std::cout<<std::endl;
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
		drawer.draw_faction(&window, &player_faction);
		drawer.draw_faction(&window, &opponent_faction);
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
	else if(event.type == sf::Event::KeyPressed){
		if(event.key.code == sf::Keyboard::Escape)
			window.close();
		else if(event.key.code == sf::Keyboard::M)
			std::cout<<"Move command"<<std::endl;
	}
	else if(event.type == sf::Event::MouseButtonPressed){
		if(event.mouseButton.button == sf::Mouse::Left){
			if(!second_click){
				sf::Vector2i tile_pos = get_mouse_tile(&window);
				p_selected = player_faction.get_piece_by_pos(tile_pos);
				second_click = true;
			}
			else{
				sf::Vector2i tile_dest = get_mouse_tile(&window);
				if(p_selected != NULL)
					if(p_selected->check_move(tile_dest))
						p_selected->set_position(tile_dest);
				second_click = false;
			}
		}
	}

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
