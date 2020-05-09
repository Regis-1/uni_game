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

	std::cout<<std::endl;
}

void Drawer::draw_text(sf::RenderWindow *win, float x, float y, std::string content, int size, sf::Color color){
	sf::Text text;
	text.setFont(font);
	text.setString(content);
	text.setCharacterSize(size);
	text.setFillColor(color);
	text.setPosition(x,y);
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

	t_sprite.setTexture(tex);
	win->draw(t_sprite);
}
