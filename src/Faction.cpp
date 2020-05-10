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
