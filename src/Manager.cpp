#include "../include/Manager.hh"

Manager::Manager(int dim_x, int dim_y, std::string title){
	window.create(sf::VideoMode(dim_x, dim_y), title, sf::Style::Titlebar | sf::Style::Close);
	drawer = Drawer("Lazer84.ttf");
	stats = Stats();
	audio_player = AudioPlayer(sf::Vector2i(294,250));
	size.x = dim_x;
	size.y = dim_y;

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
		drawer.draw_stats(&window, &stats);
		drawer.draw_audioplayer(&window, &audio_player);
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
		sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
		if(mouse_pos.x < 137*2)
			click_on_board(event);
		else
			click_on_menu(event);
	}

	return 0;
}

sf::Vector2i Manager::get_mouse_tile(){
	sf::Vector2i tile;
	sf::Vector2i l_pos = sf::Mouse::getPosition(window);
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

void Manager::click_on_board(sf::Event event){
	if(event.mouseButton.button == sf::Mouse::Left){
		if(!second_click){
			sf::Vector2i tile_pos = get_mouse_tile();
			p_selected = player_faction.get_piece_by_pos(tile_pos);
			if(p_selected != NULL)
				second_click = true;
		}
		else{
			std::vector<sf::Vector2i> of_positions = opponent_faction.get_faction_pos();
			std::vector<sf::Vector2i> pf_positions = player_faction.get_faction_pos();
			std::vector<sf::Vector2i> a_moves;
			sf::Vector2i tile_dest = get_mouse_tile();
			if(p_selected != NULL){
				a_moves = p_selected->get_available_moves(of_positions, pf_positions);
				if(std::find(a_moves.begin(), a_moves.end(), tile_dest) != a_moves.end()){
					p_selected->set_position(tile_dest);
					p_selected->set_first_move(false);
				}
			}
			second_click = false;
		}
	}
}

void Manager::click_on_menu(sf::Event event){
	if(event.mouseButton.button == sf::Mouse::Left){
		sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
		if(mouse_pos.x>294 && mouse_pos.x<294+8*2 &&
			 mouse_pos.y>250 && mouse_pos.y<250+8*2){
			if(!active_player){
				audio_player.play();
				active_player = true;
			}
		}	
		else if(mouse_pos.x>294+OFFSET*1*2 && mouse_pos.x<294+OFFSET*1*2+8*2 &&
						mouse_pos.y>250 && mouse_pos.y<250+8*2){
			if(active_player){
				audio_player.stop();
				active_player = false;
			}
		}
		else if(mouse_pos.x>294+OFFSET*2*2 && mouse_pos.x<294+OFFSET*2*2+8*2 &&
						mouse_pos.y>250 && mouse_pos.y<250+8*2){
			if(!active_player){
				audio_player.prev();
			}
			else{
				audio_player.prev_forced();
				audio_player.play();
			}
		}
		else if(mouse_pos.x>294+OFFSET*3*2 && mouse_pos.x<294+OFFSET*3*2+8*2 &&
						mouse_pos.y>250 && mouse_pos.y<250+8*2){
			if(!active_player){
				audio_player.next();
			}
			else{
				audio_player.next_forced();
				audio_player.play();
			}
		}
	}
}
