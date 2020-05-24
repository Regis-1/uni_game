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

Piece *Faction::get_piece_by_id(int id){
	Piece *piece = NULL;
	if(id<8)
		if(!pawns[id]->is_captured())
			piece = pawns[id];
	if(id>=8 && id<10)
		if(!bishops[id%8]->is_captured())
			piece = bishops[id%8];
	if(id>=10 && id<12)
		if(!knights[id%10]->is_captured())
			piece = knights[id%10];
	if(id>=12 && id<14)
		if(!rooks[id%12]->is_captured())
			piece = rooks[id%12];
	if(id==14)
		if(!queen->is_captured())
			piece = queen;
	if(id == 15)	
		if(!king->is_captured())
			piece = king;

	return piece;
}

Faction::~Faction(){
	for(int i=0; i<8; i++){
		delete pawns[i];
		if(i<2){
			delete bishops[i];
			delete knights[i];
			delete rooks[i];
		}
	}
	delete queen;
	delete king;
}

Faction::Faction(const Faction &F){
	for(int i=0; i<8; i++){
		pawns[i] = new Pawn();
		*(pawns[i]) = F.get_pawn(i);
	}
	for(int i=0; i<2; i++){
		bishops[i] = new Bishop();
		knights[i] = new Knight();
		rooks[i] = new Rook();
		*(bishops[i]) = F.get_bishop(i);
		*(knights[i]) = F.get_knight(i);
		*(rooks[i]) = F.get_rook(i);
	}
	queen = new Queen();
	*(queen) = F.get_queen();
	king = new King();
	*(king) = F.get_king();
}

void Faction::set_killed(bool k){
	this->killed = k;
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
		if(p_piece->is_captured())
			p_piece = NULL;
		pieces.push_back(p_piece);
	}
	for(int i=0; i<2; i++){
		p_piece = bishops[i];
		if(p_piece->is_captured())
			p_piece = NULL;
		pieces.push_back(p_piece);
	}
	for(int i=0; i<2; i++){
		p_piece = knights[i];
		if(p_piece->is_captured())
			p_piece = NULL;
		pieces.push_back(p_piece);
	}
	for(int i=0; i<2; i++){
		p_piece = rooks[i];
		if(p_piece->is_captured())
			p_piece = NULL;
		pieces.push_back(p_piece);
	}
	p_piece = queen;
	if(p_piece->is_captured())
		p_piece = NULL;
	pieces.push_back(p_piece);
	p_piece = king;
	if(p_piece->is_captured())
		p_piece = NULL;
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
			last_pos = piece->get_position();
			moved_piece = new Piece();
			moved_piece = piece;
			piece->set_position(pos);
			after_move(pos, opponent_faction);
			piece->set_first_move(false);
			tmp_state = is_check(opponent_faction);
			if(tmp_state == GameState::player_check){
				return GameState::player_check;
			}
		}
		else{
			std::cout<<"Invalid move!"<<std::endl;
			return GameState::player_move;
		}
	}

	if(tmp_state == GameState::opponent_check)
		return GameState::opponent_check;
	else
		return GameState::opponent_move;
}

void Faction::capture_piece(int id, bool kill){
	if(id<8)
		if(kill)
			pawns[id]->capture();
		else
			pawns[id]->revive();
	else if(id>=8 && id<10)
		if(kill)
			bishops[id%8]->capture();
		else
			bishops[id%8]->revive();
	else if(id>=10 && id<12)
		if(kill)
			knights[id%10]->capture();
		else
			knights[id%10]->revive();
	else if(id>=12 && id<14)
		if(kill)
			rooks[id%12]->capture();
		else
			rooks[id%12]->revive();
	else if(id==14)
		if(kill)
			queen->capture();
		else
			queen->revive();
	else
		if(kill)
			king->capture();
		else
			king->revive();
}

void Faction::revive_piece(int id){
	capture_piece(id, false);
}

void Faction::print_padd(){
	std::cout<<pawns[0]<<std::endl;
}

int Faction::calculate_value(){
	std::vector<Piece *> pieces = get_all_pieces();
	int whole_value = 0;
	for(int i=0; i<16; i++){
		if(pieces[i] != NULL){
			whole_value += pieces[i]->get_cost();
		}
	}
	return whole_value;
}

void Faction::undo_move(Faction *opponent_f){
	moved_piece->set_position(last_pos);
	if(killed)
		opponent_f->revive_piece(id_of_killed);
	killed = false;
	moved_piece = NULL;
}

//Getters of each piece
Pawn Faction::get_pawn(int i) const{
	Pawn p = *(pawns[i]);
	return p;
}
Bishop Faction::get_bishop(int i) const{
	Bishop b = *(bishops[i]);
	return b;
}
Knight Faction::get_knight(int i) const{
	Knight k = *(knights[i]);
	return k;
}
Rook Faction::get_rook(int i) const{
	Rook r = *(rooks[i]);
	return r;
}
Queen Faction::get_queen() const{
	Queen q = *queen;
	return q;
}
King Faction::get_king() const{
	King k = *king;
	return k;
}

/* PRIVATE METHODS */
void Faction::after_move(sf::Vector2i pos, Faction *opponent_faction){
	Piece *piece = opponent_faction->get_piece_by_pos(pos);
	if(piece != NULL){
		id_of_killed = piece->get_id();
		opponent_faction->capture_piece(id_of_killed);
		killed = true;
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
