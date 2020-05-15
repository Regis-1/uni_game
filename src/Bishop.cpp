#include "../include/Bishop.hh"

Bishop::Bishop(Team team, sf::Vector2i pos, bool enemy){
	this->position = pos;
	this->team = team;
	this->enemy = enemy;

	this->piece.setPosition(sf::Vector2f(1+17*2*pos.x, 1+17*2*pos.y));

	if(team == Team::blue)
		this->tex_path = this->tex_path+"bishopB.png";
	else
		this->tex_path = this->tex_path+"bishopY.png";
}

std::vector<sf::Vector2i> Bishop::get_available_moves(){
	std::vector<sf::Vector2i> available_moves;
	sf::Vector2i versors[4] = {sf::Vector2i(1,-1), sf::Vector2i(1,1), sf::Vector2i(-1,1), sf::Vector2i(-1,-1)};
	sf::Vector2i t_vec;
	int alfa = 1;
	for(int i=0; i<4; i++){
		while(true){
			t_vec = versors[i] * alfa;
			t_vec = t_vec + this->position;
			if(t_vec.x<0 || t_vec.x > 7 || t_vec.y<0 || t_vec.y>7)
				break;
			available_moves.push_back(t_vec);
			alfa++;
		}
		alfa = 1;
	}
	return available_moves;
}
