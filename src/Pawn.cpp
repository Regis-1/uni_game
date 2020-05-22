#include "../include/Pawn.hh"

Pawn::Pawn(Team team, sf::Vector2i pos, bool enemy, int id){
	this->position = pos;
	this->team = team;
	this->enemy = enemy;

	if(!enemy)
		this->cost = 10;
	else
		this->cost = -10;

	this->piece.setPosition(sf::Vector2f(1+17*2*pos.x, 1+17*2*pos.y));
	set_id(id);
	
	if(team == Team::blue)
		this->tex_path = this->tex_path+"pawnB.png";
	else
		this->tex_path = this->tex_path+"pawnY.png";
}

std::vector<sf::Vector2i> Pawn::get_available_moves(std::vector<sf::Vector2i> ofp, std::vector<sf::Vector2i> pfp){
	std::vector<sf::Vector2i> available_moves;
	sf::Vector2i attack_vec[2];
	if(!this->enemy){
		attack_vec[0] = sf::Vector2i(1,-1);
		attack_vec[1] = sf::Vector2i(-1,-1);
	}
	else{
		attack_vec[0] = sf::Vector2i(1,1);
		attack_vec[1] = sf::Vector2i(-1,1);
	}
	sf::Vector2i t_vec;
	if(first_move){
		if(!this->enemy)
			t_vec = this->position + sf::Vector2i(0,-2);
		else
			t_vec = this->position + sf::Vector2i(0,2);

		if(std::find(ofp.begin(), ofp.end(), t_vec) == ofp.end() && std::find(pfp.begin(), pfp.end(), t_vec) == pfp.end())
			available_moves.push_back(t_vec);
	}

	if(!this->enemy)
		t_vec = this->position + sf::Vector2i(0,-1);
	else
		t_vec = this->position + sf::Vector2i(0,1);
	if(!(t_vec.y > 7 || t_vec.y < 0))
		if(std::find(ofp.begin(), ofp.end(), t_vec) == ofp.end() && std::find(pfp.begin(), pfp.end(), t_vec) == pfp.end()){
			available_moves.push_back(t_vec);
		}
		else
			if(first_move)
				available_moves.clear();

	for(int i=0; i<2; i++){
		t_vec = this->position + attack_vec[i];
		if(std::find(ofp.begin(), ofp.end(), t_vec) != ofp.end())
			available_moves.push_back(t_vec);
	}

	return available_moves;
}
