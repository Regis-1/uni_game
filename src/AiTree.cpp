#include "../include/AiTree.hh"

AiTree::AiTree(int dep, Faction opponent_f, Faction player_f){
	this->depth = dep;
	this->opponent_faction = new Faction(opponent_f);
	this->player_faction = new Faction(player_f);
}

AiTree::AiTree(Piece *piece, sf::Vector2i move, bool maximising, int dep, Faction opponent_f, Faction player_f){
	this->depth = dep;
	this->opponent_faction = new Faction(opponent_f);
	this->player_faction = new Faction(player_f);

	this->root = false;
	this->maximising_player = maximising;
	this->local_move = move;
	if(this->maximising_player)
		this->local_piece = opponent_faction->get_piece_by_id(piece->get_id());
	else
		this->local_piece = player_faction->get_piece_by_id(piece->get_id());
}

void AiTree::insert_child(Piece *piece, sf::Vector2i move, bool maximising){
	AiTree *child;
	child = new AiTree(piece, move, maximising, depth-1, *opponent_faction, *player_faction);
	this->children.push_back(child);
}

int AiTree::evaluate(){
	GameState tmp_state;
	std::vector<sf::Vector2i> available_moves;
	std::vector<sf::Vector2i> of_pos;
	std::vector<sf::Vector2i> pf_pos;
	std::vector<Piece *> pieces;
	std::vector<int> costs;
	std::vector<int>::iterator minimax_result;
	int final_cost = 0;
	int n_children = 0;

	if(!root){
		if(!maximising_player)
			tmp_state = player_faction->move_piece(local_piece, local_move, opponent_faction);
		else
			tmp_state = opponent_faction->move_piece(local_piece, local_move, player_faction);
	}

	if(depth == 0){
		int maxi_pvalue = player_faction->calculate_value();
		int mini_pvalue = opponent_faction->calculate_value();
		return (maxi_pvalue + mini_pvalue);
	}

	of_pos = opponent_faction->get_faction_pos();
	pf_pos = player_faction->get_faction_pos();

	if(maximising_player){
		pieces = player_faction->get_all_pieces();
		for(int i=0; i<16; i++)
			if(pieces[i] != NULL){
				available_moves = pieces[i]->get_available_moves(of_pos, pf_pos);
				for(int j=0; j<(int)available_moves.size(); j++)
					insert_child(pieces[i], available_moves[j], false);
			}
	}
	else{ /*minimising_player*/
		pieces = opponent_faction->get_all_pieces();
		for(int i=0; i<16; i++)
			if(pieces[i] != NULL){
				available_moves = pieces[i]->get_available_moves(pf_pos, of_pos);
				for(int j=0; j<(int)available_moves.size(); j++)
					insert_child(pieces[i], available_moves[j], true);
			}
	}

	for(int i=0; i<(int)children.size(); i++){
		costs.push_back(children[i]->evaluate());
	}
	if(maximising_player)
		minimax_result = std::max_element(costs.begin(), costs.end());
	else
		minimax_result = std::min_element(costs.begin(), costs.end());

	final_cost = costs[std::distance(costs.begin(), minimax_result)];

	if(root){
		this->local_move = children[std::distance(costs.begin(), minimax_result)]->get_local_move();
		this->local_piece = children[std::distance(costs.begin(), minimax_result)]->get_local_piece();
	}

	return final_cost;
}
