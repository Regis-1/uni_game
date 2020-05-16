#include "../include/Pawn.hh"

Pawn::Pawn(Team team, sf::Vector2i pos, bool enemy, int id){
	this->position = pos;
	this->team = team;
	this->enemy = enemy;

	this->piece.setPosition(sf::Vector2f(1+17*2*pos.x, 1+17*2*pos.y));
	set_id(id);
	
	if(team == Team::blue)
		this->tex_path = this->tex_path+"pawnB.png";
	else
		this->tex_path = this->tex_path+"pawnY.png";
}

std::vector<sf::Vector2i> Pawn::get_available_moves(std::vector<sf::Vector2i> ofp, std::vector<sf::Vector2i> pfp){
	std::vector<sf::Vector2i> available_moves;
	sf::Vector2i t_vec;
	if(!this->enemy)
		t_vec = this->position + sf::Vector2i(0,-2);
	else
		t_vec = this->position + sf::Vector2i(0,2);

	if(first_move)
		if(std::find(ofp.begin(), ofp.end(), t_vec) == ofp.end() && std::find(pfp.begin(), pfp.end(), t_vec) == pfp.end())
			available_moves.push_back(t_vec);

	if(!this->enemy)
		t_vec = this->position + sf::Vector2i(0,-1);
	else
		t_vec = this->position + sf::Vector2i(0,1);
	if(std::find(ofp.begin(), ofp.end(), t_vec) == ofp.end() && std::find(pfp.begin(), pfp.end(), t_vec) == pfp.end()){
		available_moves.push_back(t_vec);
	}
	else
		if(first_move)
			available_moves.clear();

	return available_moves;
}
