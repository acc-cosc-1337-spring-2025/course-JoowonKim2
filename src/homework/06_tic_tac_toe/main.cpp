#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include <memory>
#include <iostream>

using std::string;
using std::cin;
using std::cout;

int main() 
{
	TicTacToeManager manager;
    std::unique_ptr<TicTacToe> game;
	string p1;
	string choice = "y";
    int X, O, T;
	int game_type;

    std::cout << "Enter 3 for 3x3 or 4 for 4x4 TicTacToe: ";
    std::cin >> game_type;

    if (game_type == 3)
        game = std::make_unique<TicTacToe3>();
    else
        game = std::make_unique<TicTacToe4>();

	do
    {
        while (true) {
            cout << "Choose first player (X or O): ";
            cin >> p1;

            if (p1 == "X" || p1 == "O") {
                break; 
            } else {
                cout << "Invalid input. Please choose X or O.\n";
            }
        }

        game->start_game(p1);
        int position;

        while (!game->game_over())
        {
            game->display_board();
			cout << "Player " << (game->get_player() == "X" ? "X" : "O") << ", enter the position (1-9) to mark: ";
            cin >> position;
            game->mark_board(position);
        }

        game->display_board();

        string winner = game->get_winner();
        if (winner == "") {
            cout << "The game is a tie!\n";
        } else {
            cout << "Player " << winner << " wins!\n";
        }

        manager.save_game(game);
		manager.get_winner_total(X, O, T);
        cout<<"X wins: "<< X <<"\n"<<"O wins: "<< O <<"\n"<<"Ties: "<< T <<"\n";

        cout << "Enter y to play again, other key to quit: ";
        cin >> choice;
        if (game_type == 3)
            game = std::make_unique<TicTacToe3>();
        else
            game = std::make_unique<TicTacToe4>();

    } while (choice == "y" || choice == "Y");
	
	return 0;
}