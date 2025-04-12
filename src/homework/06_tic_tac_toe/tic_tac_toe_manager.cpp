//cpp
#include "tic_tac_toe_manager.h"

void TicTacToeManager::get_winner_total(int& X, int& O, int& T)
{
    X = x_win;
    O = o_win;
    T = ties;
}

void TicTacToeManager::save_game(TicTacToe game)
{
    games.push_back(game);
    update_winner_count(game.get_winner());
}

void TicTacToeManager::update_winner_count(std::string winner)
{
    if (winner == "X")
        x_win += 1;
    else if (winner == "O")
        o_win += 1;
    else
        ties += 1;
}