#include "tic_tac_toe.h"
#include<iostream>
#include<string>

using std::string;
using std::cin;
using std::cout;


int main() 
{
	TicTacToe game;
	string p1;
	string choice = "y";
	
	do
	{
		cout<<"Enter first player: ";
		cin>>p1;

		game.start_game(p1);

		int position;
		while(!game.game_over())
		{
			game.display_board();
			cout<<"Enter a position(1-9): ";
			cin>>position;
			game.mark_board(position);
		}

		cout<<"Would you like to play again(Y/N): ";
		cin>>choice;


	} while(choice == "Y" or choice == "y");

	return 0;
}