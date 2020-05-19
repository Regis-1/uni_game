#include "../include/Faction.hh"

Faction::Faction(Team t, bool enemy){
	int id = 0;

	int row1 = 6;
	int row2 = 7;

	if(enemy){
		row1=1;
		row2=0;
	}

	for(int i=0; i<8; i++){
		pawns[i] = new Pawn(t, sf::Vector2i(i,row1), enemy, id++);
	}
	bishops[0] = new Bishop(t, sf::Vector2i(2,row2), enemy, id++);
	bishops[1] = new Bishop(t, sf::Vector2i(5,row2), enemy, id++);
	knights[0] = new Knight(t, sf::Vector2i(1,row2), enemy, id++);
	knights[1] = new Knight(t, sf::Vector2i(6,row2), enemy, id++);
	rooks[0] = new Rook(t, sf::Vector2i(0,row2), enemy, id++);
	rooks[1] = new Rook(t, sf::Vector2i(7,row2), enemy, id++);
	queen = new Queen(t, sf::Vector2i(3,row2), enemy, id++);
	king = new King(t, sf::Vector2i(4,row2), enemy, id++);

	std::cout<<"Whole faction created!"<<std::endl;
}

Piece* Faction::get_piece_by_pos(sf::Vector2i pos){
	std::vector<Piece *> pieces = get_all_pieces();
	for(int i=0; i<16; i++){
		if(pieces[i] != NULL)
			if(pieces[i]->get_position() == pos)
				return pieces[i];
	}
	return NULL;
}

std::vector<sf::Vector2i> Faction::get_faction_pos(){
	std::vector<sf::Vector2i> faction_pos;
	std::vector<Piece *> pieces = get_all_pieces();

	for(int i=0; i<16; i++)
		if(pieces[i] != NULL)
			faction_pos.push_back(pieces[i]->get_position());

	return faction_pos;
}

std::vector<Piece *> Faction::get_all_pieces(){
	std::vector<Piece *> pieces;
	Piece * p_piece = NULL;
	for(int i=0; i<8; i++){
		p_piece = pawns[i];
		pieces.push_back(p_piece);
	}
	for(int i=0; i<2; i++){
		p_piece = bishops[i];
		pieces.push_back(p_piece);
	}
	for(int i=0; i<2; i++){
		p_piece = knights[i];
		pieces.push_back(p_piece);
	}
	for(int i=0; i<2; i++){
		p_piece = rooks[i];
		pieces.push_back(p_piece);
	}
	p_piece = queen;
	pieces.push_back(p_piece);
	p_piece = king;
	pieces.push_back(p_piece);

	return pieces;
}

GameState Faction::move_piece(Piece *piece, sf::Vector2i pos, Faction *opponent_faction){
	std::vector<sf::Vector2i> of_positions = opponent_faction->get_faction_pos();
	std::vector<sf::Vector2i> pf_positions = get_faction_pos();
	std::vector<sf::Vector2i> a_moves;
	GameState tmp_state;
	if(piece != NULL){
		a_moves = piece->get_available_moves(of_positions, pf_positions);
		if(std::find(a_moves.begin(), a_moves.end(), pos) != a_moves.end()){
			piece->set_position(pos);
			after_move(pos, opponent_faction);
			piece->set_first_move(false);
			tmp_state = is_check(opponent_faction);
			if(tmp_state == GameState::player_check){
				return GameState::player_check;
			}
		}
		else
			return GameState::player_move;
	}
	if(tmp_state == GameState::opponent_check)
		return GameState::opponent_check;
	else
		return GameState::opponent_move;
}

void Faction::kill_piece(int id){
	if(id<8)
		pawns[id] = NULL;
	else if(id>=8 && id<10)
		bishops[id%8] = NULL;
	else if(id>=10 && id<12)
		knights[id%10] = NULL;
	else if(id>=12 && id<14)
		rooks[id%12] = NULL;
	else if(id==14)
		queen = NULL;
	else
		king = NULL;
}

/* PRIVATE METHODS */
void Faction::after_move(sf::Vector2i pos, Faction *opponent_faction){
	Piece *piece = opponent_faction->get_piece_by_pos(pos);
	if(piece != NULL){
		opponent_faction->kill_piece(piece->get_id());
	}
}

GameState Faction::is_check(Faction *opponent_faction){
	std::vector<sf::Vector2i> opponent_pos = opponent_faction->get_faction_pos();
	std::vector<sf::Vector2i> player_pos = get_faction_pos();
	std::vector<Piece *> opponent_pieces = opponent_faction->get_all_pieces();
	std::vector<Piece *> player_pieces = get_all_pieces();
	std::vector<sf::Vector2i> available_moves;

	for(int i=0; i<16; i++){
		if(player_pieces[i] != NULL){
			available_moves = player_pieces[i]->get_available_moves(opponent_pos, player_pos);
			for(int j=0; j<(int)available_moves.size(); j++)
				if(available_moves[j] == opponent_pieces[15]->get_position())
					return GameState::opponent_check;
		}
	}
	for(int i=0; i<16; i++){
		if(opponent_pieces[i] != NULL){
			available_moves = opponent_pieces[i]->get_available_moves(player_pos, opponent_pos);
			for(int j=0; j<(int)available_moves.size(); j++)
				if(available_moves[j] == player_pieces[15]->get_position())
					return GameState::player_check;
		}
	}

	return GameState::opponent_move;
}
