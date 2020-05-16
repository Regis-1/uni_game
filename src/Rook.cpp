#include "../include/Rook.hh"

Rook::Rook(Team team, sf::Vector2i pos, bool enemy, int id){
	this->position = pos;
	this->team = team;
	this->enemy = enemy;

	this->piece.setPosition(sf::Vector2f(1+17*2*pos.x, 1+17*2*pos.y));
	set_id(id);
	
	if(team == Team::blue)
		this->tex_path = this->tex_path+"rookB.png";
	else
		this->tex_path = this->tex_path+"rookY.png";
}

std::vector<sf::Vector2i> Rook::get_available_moves(std::vector<sf::Vector2i> ofp, std::vector<sf::Vector2i> pfp){
	std::vector<sf::Vector2i> available_moves;
	sf::Vector2i versors[4] = {sf::Vector2i(0,-1), sf::Vector2i(1,0), sf::Vector2i(0,1), sf::Vector2i(-1,0)};
	sf::Vector2i t_vec;
	int alfa = 1;
	for(int i=0; i<4; i++){
		while(true){
			t_vec = versors[i] * alfa;
			t_vec = t_vec + this->position;
			if(t_vec.x<0 || t_vec.x > 7 || t_vec.y<0 || t_vec.y>7)
				break;
			else if(std::find(pfp.begin(), pfp.end(), t_vec) != pfp.end())
				break;
			available_moves.push_back(t_vec);
			if(std::find(ofp.begin(), ofp.end(), t_vec) != ofp.end())
				break;
			alfa++;
		}
		alfa = 1;
	}
	return available_moves;
}
