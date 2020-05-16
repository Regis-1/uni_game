#include "../include/Faction.hh"

Faction::Faction(Team t, bool enemy){
	int row1 = 6;
	int row2 = 7;

	if(enemy){
		row1=1;
		row2=0;
	}

	for(int i=0; i<8; i++){
		pawns[i] = Pawn(t, sf::Vector2i(i,row1), enemy);
	}
	bishops[0] = Bishop(t, sf::Vector2i(2,row2), enemy);
	bishops[1] = Bishop(t, sf::Vector2i(5,row2), enemy);
	knights[0] = Knight(t, sf::Vector2i(1,row2), enemy);
	knights[1] = Knight(t, sf::Vector2i(6,row2), enemy);
	rooks[0] = Rook(t, sf::Vector2i(0,row2), enemy);
	rooks[1] = Rook(t, sf::Vector2i(7,row2), enemy);
	queen = Queen(t, sf::Vector2i(3,row2), enemy);
	king = King(t, sf::Vector2i(4,row2), enemy);

	std::cout<<"Whole faction created!"<<std::endl;
}

Piece* Faction::get_piece_by_pos(sf::Vector2i pos){
	bool found = false;
	Piece *p_piece = NULL;
	for(int i=0; i<8 && !found; i++)
		if(pawns[i].get_position() == pos){
			p_piece = pawns + i;
			found = true;
			break;
		}

	for(int i=0; i<2 && !found; i++){
		if(bishops[i].get_position() == pos && !found){
			p_piece = bishops + i;
			found = true;
			break;
		}
		if(knights[i].get_position() == pos && !found){
			p_piece = knights + i;
			found = true;
			break;
		}
		if(rooks[i].get_position() == pos && !found){
			p_piece = rooks + i;
			found = true;
			break;
		}
	}

	if(queen.get_position() == pos)
		p_piece = &queen;
	else if(king.get_position() == pos)
		p_piece = &king;

	return p_piece;
}

std::vector<sf::Vector2i> Faction::get_faction_pos(){
	std::vector<sf::Vector2i> faction_pos;
	for(int i=0; i<8; i++){
		if(i<2){
			if(i==0){
				faction_pos.push_back(king.get_position());
				faction_pos.push_back(queen.get_position());
			}
			faction_pos.push_back(bishops[i].get_position());
			faction_pos.push_back(knights[i].get_position());
			faction_pos.push_back(rooks[i].get_position());
		}
		faction_pos.push_back(pawns[i].get_position());
	}
	return faction_pos;
}
