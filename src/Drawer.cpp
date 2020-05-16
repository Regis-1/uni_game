#include "../include/Drawer.hh"

Drawer::Drawer(std::string font_file){
	std::string path = "res/";
	std::string path_font = path + font_file;
	if(!font.loadFromFile(path_font))
		std::cout<<"Error while loading font!"<<std::endl;
	else
		std::cout<<"Font loaded!"<<std::endl;

	std::string path_board = path + "board.png";
	if(!board_tex.loadFromFile(path_board))
		std::cout<<"Error while loading board texture!"<<std::endl;
	else
		std::cout<<"Board texture loaded!"<<std::endl;
}

void Drawer::draw_text(sf::RenderWindow *win, sf::Vector2f pos, std::string content, int size, sf::Color color){
	sf::Text text;
	text.setFont(font);
	text.setString(content);
	text.setCharacterSize(size);
	text.setFillColor(color);
	text.setPosition(pos.x,pos.y);
	win->draw(text);
}

void Drawer::draw_board(sf::RenderWindow *win){
	sf::Sprite board_sprite;
	board_sprite.setTexture(board_tex);
	board_sprite.setScale(2.f,2.f);
	win->draw(board_sprite);
}

void Drawer::draw_line(sf::RenderWindow *win, sf::Vector2f p1, sf::Vector2f p2, sf::Color color){
	sf::Vertex line[] = {sf::Vertex(p1), sf::Vertex(p2)};
	win->draw(line, 2, sf::Lines);
}

void Drawer::draw_piece(sf::RenderWindow *win, Piece *piece){
	sf::Texture tex;
	sf::Sprite t_sprite = piece->get_sprite();

	if(!tex.loadFromFile(piece->get_tex_path()))
		std::cout<<"Error while loading piece texture!"<<std::endl;

	t_sprite.setScale(2.f, 2.f);
	if(piece->get_enemy()){
		t_sprite.setOrigin(8*2, 8*2);
		t_sprite.rotate(180.f);
	}
	t_sprite.setTexture(tex);
	win->draw(t_sprite);
}

void Drawer::draw_faction(sf::RenderWindow *win, Faction *f){
	std::vector<Piece *> pieces = f->get_all_pieces();
	for(int i=0; i<16; i++)
		if(pieces[i] != NULL)
			draw_piece(win, pieces[i]);
}

void Drawer::draw_audioplayer(sf::RenderWindow *win, AudioPlayer *a){
	Button *p_button = a->get_buttons();
	sf::Sprite t_sprite;
	sf::Texture t_tex;
	for(int i=0; i<4; i++){
		t_sprite = (p_button+i)->get_sprite();
		if(!t_tex.loadFromFile((p_button+i)->get_btn_tex_path())){
			std::cout<<"Error while loading button texture!"<<std::endl;
		}
		t_sprite.setTexture(t_tex);
		t_sprite.setScale(2.f, 2.f);
		win->draw(t_sprite);
	}
}

void Drawer::draw_stats(sf::RenderWindow *win, Stats *s){
	sf::Texture t_tex;
	sf::Sprite t_sprite;
	std::string *t_str = s->get_players();
	sf::Vector2f **t_pos = s->get_icons_pos();
	int **t_counter = s->get_piece_counter();
	sf::Color *t_color = s->get_counter_colors();

	draw_text(win, sf::Vector2f(309, 110), t_str[0]);
	draw_text(win, sf::Vector2f(294, 180), t_str[1]);
	
	t_str = s->get_icons_names();
	for(int i=0; i<2; i++)
		for(int j=0; j<5; j++){
			if(i==0){
				if(!t_tex.loadFromFile("res/"+t_str[j]+"Y.png"))
					std::cout<<"Error while loading icon texture"<<std::endl;
			}
			else{
				if(!t_tex.loadFromFile("res/"+t_str[j]+"B.png"))
					std::cout<<"Error while loading icon texture"<<std::endl;
			}
			t_sprite.setPosition(t_pos[i][j]);
			t_sprite.setTexture(t_tex);
			win->draw(t_sprite);
			draw_text(win, t_pos[i][j]+sf::Vector2f(4,16), std::to_string(t_counter[i][j]), 12, t_color[j]);
		}
}
