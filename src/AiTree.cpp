#include "../include/AiTree.hh"

AiTree::AiTree(int dep, Faction opponent_f, Faction player_f){
	this->depth = dep;
	this->opponent_faction = new Faction(opponent_f);
	this->player_faction = new Faction(player_f);
	this->alpha = -infinity;
	this->beta = infinity;
}

AiTree::AiTree(Piece *piece, sf::Vector2i move, bool maximising, int alp, int bet, int dep, Faction opponent_f, Faction player_f){
	this->depth = dep;
	this->opponent_faction = new Faction(opponent_f);
	this->player_faction = new Faction(player_f);
	this->alpha = alp;
	this->beta = bet;

	this->root = false;
	this->maximising_player = maximising;
	this->local_move = move;
	if(this->maximising_player)
		this->local_piece = opponent_faction->get_piece_by_id(piece->get_id());
	else
		this->local_piece = player_faction->get_piece_by_id(piece->get_id());
}

AiTree::~AiTree(){
	if(root){
		delete opponent_faction;
		delete player_faction;
		delete local_piece;
	}
}

void AiTree::insert_child(Piece *piece, sf::Vector2i move, bool maximising, int alp, int bet){
	this->children.push_back(std::make_unique<AiTree>(piece, move, maximising, alp, bet, depth-1, *opponent_faction, *player_faction));
}

// >>MAIN MINIMAX ALGORITHM FUNCTION<< //
int AiTree::evaluate(){
	GameState tmp_state;
	std::vector<sf::Vector2i> available_moves;
	std::vector<sf::Vector2i> of_pos;
	std::vector<sf::Vector2i> pf_pos;
	std::vector<Piece *> pieces;
	std::vector<int> costs;
	std::vector<int>::iterator minimax_result;
	int final_cost = 0;

	//START OF MINIMAX ALGORITHM
	if(!root){
		if(!maximising_player)
			tmp_state = player_faction->move_piece(local_piece, local_move, opponent_faction);
		else
			tmp_state = opponent_faction->move_piece(local_piece, local_move, player_faction);

		if(tmp_state==GameState::opponent_check){
			final_cost = (maximising_player)?-900:900;
			return final_cost;
		}
		else if(tmp_state==GameState::player_check){
			final_cost = (maximising_player)?900:-900;
			return final_cost;
		}

	}

	if(depth == 0){
		int maxi_pvalue = player_faction->calculate_value();
		int mini_pvalue = opponent_faction->calculate_value();
		return (maxi_pvalue + mini_pvalue);
	}

	of_pos = opponent_faction->get_faction_pos();
	pf_pos = player_faction->get_faction_pos();

	//INSERTING CHILDREN FOR PREDICTING NEXT MOVE
	if(maximising_player){
		final_cost = -infinity;
		pieces = player_faction->get_all_pieces();
		for(int i=0; i<16; i++)
			if(pieces[i] != NULL){
				available_moves = pieces[i]->get_available_moves(of_pos, pf_pos);
				for(int j=0; j<(int)available_moves.size(); j++)
					insert_child(pieces[i], available_moves[j], false, alpha, beta);
			}
	}
	else{ /*minimising_player*/
		final_cost = infinity;
		pieces = opponent_faction->get_all_pieces();
		for(int i=0; i<16; i++)
			if(pieces[i] != NULL){
				available_moves = pieces[i]->get_available_moves(pf_pos, of_pos);
				for(int j=0; j<(int)available_moves.size(); j++)
					insert_child(pieces[i], available_moves[j], true, alpha, beta);
			}
	}

	for(int i=0; i<(int)children.size(); i++){
		costs.push_back(children[i]->evaluate());

		if(maximising_player){
			minimax_result = std::max_element(costs.begin(), costs.end());
			final_cost = costs[std::distance(costs.begin(), minimax_result)];
			alpha = std::max(alpha, final_cost);
			if(alpha >= beta)
				break;
		}
		else{
			minimax_result = std::min_element(costs.begin(), costs.end());
			final_cost = costs[std::distance(costs.begin(), minimax_result)];
			beta = std::min(beta, final_cost);
			if(alpha >= beta)
				break;
		}
	}
	//END OF MINIMAX ALGORITHM

	//giving the piece and move for opponent
	if(root){
		this->local_move = children[std::distance(costs.begin(), minimax_result)]->get_local_move();
		this->local_piece = children[std::distance(costs.begin(), minimax_result)]->get_local_piece();
	}

	return final_cost;
}
