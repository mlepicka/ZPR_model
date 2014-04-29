#include <cstdio>
#include "Table.h"
#include "FactoryOfCarts.h"

#include <iostream>


int main(){


	FactoryOfCarts factory;

	//just for example
	Player* player_1,* player_2;
	player_1 = new Player;
	player_2 = new Player;
	player_1->health = 1000;
	player_2->health = 2000;

	//for example we create same deck for each player with 10 spell carts and 10 ally carts 
	for (int i = 0; i < 10; i++){
		player_1->deck.push_back(*factory.createCart(SPELL));
		player_1->deck.push_back(*factory.createCart(MONSTER));

		player_2->deck.push_back(*factory.createCart(SPELL));
		player_2->deck.push_back(*factory.createCart(MONSTER));
	}

	//we choose 3 carts to hand, it would be random or chosen by player later 
	for (int i = 0; i < 3; i++){
		player_1->getCart();
		player_2->getCart();
	}


	//create table
	Table table;

	table.player_1 = player_1;
	table.player_2 = player_2;

	int i;
	char c = 'a';
	while (c != 'q'){

		std::cout << "Gracz nr 1 rozgrywa ture" << std::endl;
		std::cout << "Wybierz karte (0-2)" << std::endl;
		std::cin >> i;
		//get cart on table
		table.carts_on_table.push_back(player_1->carts_in_hand.operator[](i));

		//make interaction
		player_1->hit(*player_2, player_1->carts_in_hand.operator[](i));
		
		//take new cart
		player_1->getCart();

		std::cout << "Gracz nr 2 rozgrywa ture" << std::endl;
		std::cout << "Wybierz karte (0-2)" << std::endl;
		std::cin >> i;
		//get cart on table
		table.carts_on_table.push_back(player_2->carts_in_hand.operator[](i));

		//make interaction
		player_2->hit(*player_1, player_2->carts_in_hand.operator[](i));

		//take new cart
		player_2->getCart();

		std::cout << "Pozosta�o �ycia : " << std::endl;
		std::cout << "Gracz 1: " << table.player_1->health << std::endl;
		std::cout << "Gracz 2: " << table.player_2->health << std::endl;

		std::cout << "Dalej? t/q" << std::endl;
		std::cin >> c;

	};
	return 0;
}