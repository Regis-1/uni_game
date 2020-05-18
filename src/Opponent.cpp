#include "../include/Opponent.hh"

Opponent::Opponent(Faction *opponent_f, Faction *player_f){
	this->player_faction = player_f;
	this->opponent_faction = opponent_f;

	std::cout<<"Opponent has been initialized."<<std::endl;
}

void Opponent::make_move(){
	std::vector<Piece *> pieces = opponent_faction->get_all_pieces();
	std::vector<sf::Vector2i> player_faction_pos = player_faction->get_faction_pos();
	std::vector<sf::Vector2i> opponent_faction_pos = opponent_faction->get_faction_pos();
	std::vector<sf::Vector2i> available_moves;

	std::srand(std::time(NULL));
	int r_piece;
	int r_move = 0;

	while(available_moves.empty()){
		r_piece = rand()%pieces.size();
		if(pieces[r_piece] != NULL)
			available_moves = pieces[r_piece]->get_available_moves(player_faction_pos, opponent_faction_pos);
	}

	r_move = rand()%available_moves.size();

	opponent_faction->move_piece(pieces[r_piece], available_moves[r_move], player_faction);
	std::cout<< "Opponent made move..." << std::endl;
}
