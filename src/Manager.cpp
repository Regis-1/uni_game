#include "../include/Manager.hh"
using namespace std::chrono_literals;

Manager::Manager(int dim_x, int dim_y, std::string title, int dep){
	drawer = Drawer("Lazer84.ttf");
	std::this_thread::sleep_for(50ms);
	stats = new Stats();
	std::this_thread::sleep_for(50ms);
	audio_player = new AudioPlayer(sf::Vector2i(294,250));
	size.x = dim_x;
	size.y = dim_y;
	this->g_state = GameState::player_move;

	std::this_thread::sleep_for(50ms);
	player_faction = new Faction(Team::blue);
	std::this_thread::sleep_for(50ms);
	opponent_faction = new Faction(Team::yellow, true);

	std::this_thread::sleep_for(50ms);
	opponent = Opponent(opponent_faction, player_faction, dep);
	std::cout<<std::endl;

	title_rollup();

	window.create(sf::VideoMode(dim_x, dim_y), title, sf::Style::Titlebar | sf::Style::Close);
}

Manager::~Manager(){
	delete audio_player;
	delete stats;
	delete opponent_faction;
	delete player_faction;
	delete p_selected;
}

int Manager::run(){
	std::cout<<"Starting the game..."<<std::endl;
	
	//game loop
	while(window.isOpen()){
		
		while(window.pollEvent(event)){
			handle_events(event);
		}

		refresh_screen();

		if(g_state == GameState::opponent_move || g_state == GameState::opponent_check){
			g_state = opponent.make_move();
			stats->update_stats(player_faction, opponent_faction);
			if(g_state == GameState::player_check)
				g_state = GameState::opponent_check;
			else if(g_state == GameState::opponent_check)
				g_state = GameState::player_check;
			else if(g_state == GameState::opponent_mate)
				std::cout<<"Check-mate! You have won!"<<std::endl;
			else
				g_state = GameState::player_move;
		}

		refresh_screen();

	}

	return 0;
}

int Manager::close(){
	std::cout<<"Closing the game..."<<std::endl;
	return 0;
}

/* PRIVATE METHODS */
//EVENTS HANDLING (MOUSE PRESSING, CLOSE REQUEST ETC.)
int Manager::handle_events(sf::Event event){
	if(event.type == sf::Event::Closed)
		window.close();
	else if(event.type == sf::Event::KeyPressed){
		if(event.key.code == sf::Keyboard::Escape)
			window.close();
	}
	else if(event.type == sf::Event::MouseButtonPressed){
		sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
		if(mouse_pos.x < 137*2 && (g_state == GameState::player_move||g_state == GameState::player_check))
			click_on_board(event);
		else
			click_on_menu(event);
	}

	return 0;
}

//TRANSFORMING MOUSE POSITION FROM FLOAT VARIABLE TO ABSTRACT BOARD POSITION
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

//HANDLING CLICKING ON BOARD SIDE
void Manager::click_on_board(sf::Event event){
	if(event.mouseButton.button == sf::Mouse::Left){
		if(!second_click){
			sf::Vector2i tile_pos = get_mouse_tile();
			p_selected = player_faction->get_piece_by_pos(tile_pos);
			if(p_selected != NULL)
				second_click = true;
		}
		else{
			sf::Vector2i tile_dest = get_mouse_tile();
			g_state = player_faction->move_piece(p_selected, tile_dest, opponent_faction);
			if(g_state == GameState::player_check){
				std::cout<<"CHECK!"<<std::endl;
				player_faction->undo_move(opponent_faction);
			}
			else
				player_faction->set_killed(false);
			stats->update_stats(player_faction, opponent_faction);
			opponent.off_distress();
			second_click = false;
		}
	}
}

//HANDLING CLICKING ON MENU SIDE
void Manager::click_on_menu(sf::Event event){
	if(event.mouseButton.button == sf::Mouse::Left){
		sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
		if(mouse_pos.x>294 && mouse_pos.x<294+8*2 &&
			 mouse_pos.y>250 && mouse_pos.y<250+8*2){
			if(!active_player){
				audio_player->play();
				active_player = true;
			}
		}	
		else if(mouse_pos.x>294+OFFSET*1*2 && mouse_pos.x<294+OFFSET*1*2+8*2 &&
						mouse_pos.y>250 && mouse_pos.y<250+8*2){
			if(active_player){
				audio_player->stop();
				active_player = false;
			}
		}
		else if(mouse_pos.x>294+OFFSET*2*2 && mouse_pos.x<294+OFFSET*2*2+8*2 &&
						mouse_pos.y>250 && mouse_pos.y<250+8*2){
			if(!active_player){
				audio_player->prev();
			}
			else{
				audio_player->prev_forced();
				audio_player->play();
			}
		}
		else if(mouse_pos.x>294+OFFSET*3*2 && mouse_pos.x<294+OFFSET*3*2+8*2 &&
						mouse_pos.y>250 && mouse_pos.y<250+8*2){
			if(!active_player){
				audio_player->next();
			}
			else{
				audio_player->next_forced();
				audio_player->play();
			}
		}
	}
}

void Manager::refresh_screen(){
	window.clear();
	drawer.draw_board(&window);
	drawer.draw_stats(&window, stats);
	drawer.draw_audioplayer(&window, audio_player);
	drawer.draw_faction(&window, player_faction);
	drawer.draw_faction(&window, opponent_faction);
	window.display();
}

void Manager::title_rollup(){
	std::this_thread::sleep_for(2s);

	std::string welcome_text =R"(
       Jakub Dudziński [248928] presents...)";
	std::cout<<welcome_text<<std::endl;
	std::this_thread::sleep_for(1s);
	welcome_text = R"(   __         _      __   __         _    __)";
	std::cout<<welcome_text<<std::endl;
	std::this_thread::sleep_for(1s);
	welcome_text = R"(  / /__ ___  (_)__ _/ /  / /_   ____(_)__/ /__ ____)";
	std::cout<<welcome_text<<std::endl;
	std::this_thread::sleep_for(1s);
	welcome_text = R"( /  '_// _ \/ / _ `/ _ \/ __/  / __/ / _  / -_) __/)";
	std::cout<<welcome_text<<std::endl;
	std::this_thread::sleep_for(1s);
	welcome_text = R"(/_/\_\/_//_/_/\_, /_//_/\__/  /_/ /_/\_,_/\__/_/)";
	std::cout<<welcome_text<<std::endl;
	std::this_thread::sleep_for(1s);
	welcome_text = R"(             /___/)";
	std::cout<<welcome_text<<std::endl<<std::endl;
	std::this_thread::sleep_for(3s);
}
