#include "../include/King.hh"

King::King(Team team, sf::Vector2i pos, bool enemy){
	this->position = pos;
	this->team = team;
	this->enemy = enemy;

	this->piece.setPosition(sf::Vector2f(1+17*2*pos.x, 1+17*2*pos.y));
	
	if(team == Team::blue)
		this->tex_path = this->tex_path+"kingB.png";
	else
		this->tex_path = this->tex_path+"kingY.png";
}

std::vector<sf::Vector2i> King::get_available_moves(){
	std::vector<sf::Vector2i> available_moves;
	sf::Vector2i versors[4] = {sf::Vector2i(0,-1), sf::Vector2i(1,-1), sf::Vector2i(1,0), sf::Vector2i(1,1)};
	sf::Vector2i t_vec;
	for(int i=0; i<4; i++){
		t_vec = this->position + versors[i];
		if(t_vec.x>=0 && t_vec.x<=7 && t_vec.y>=0 && t_vec.y<=7)
			available_moves.push_back(t_vec);

		t_vec = this->position + -versors[i];
		if(t_vec.x>=0 && t_vec.x<=7 && t_vec.y>=0 && t_vec.y<=7)
			available_moves.push_back(t_vec);
	}
	return available_moves;
}
