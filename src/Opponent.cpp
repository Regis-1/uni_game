#include "../include/Opponent.hh"

Opponent::Opponent(Faction *opponent_f, Faction *player_f, int dep){
	this->player_faction = player_f;
	this->opponent_faction = opponent_f;

	this->depth = dep;

	std::cout<<"Opponent has been initialized."<<std::endl;
}

//MAKING MINIMAX TREE AND THEN EVALUATING WHAT MOVE TO USE
GameState Opponent::make_move(){
	int final_cost = 0;
	GameState tmp_state = GameState::opponent_move;
	std::cout<<"Ai is thinking..."<<std::endl;

	ai = new AiTree(depth, *opponent_faction, *player_faction);
	final_cost = ai->evaluate();
	sf::Vector2i tmp_vec = ai->get_local_move();
	Piece *tmp_piece = ai->get_local_piece();
	Piece *piece = opponent_faction->get_piece_by_id(tmp_piece->get_id());

	delete ai;

	if(final_cost==900 && !distress)
		this->distress = true;
	else if(final_cost==900 && distress){
		return GameState::opponent_mate;
	}
	else
		this->distress = false;

	tmp_state = opponent_faction->move_piece(piece, tmp_vec, player_faction);
	std::cout<<"Ai moved."<<std::endl;
	return tmp_state;
}
