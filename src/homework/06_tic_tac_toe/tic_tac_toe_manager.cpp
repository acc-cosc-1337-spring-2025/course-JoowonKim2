//cpp
#include "tic_tac_toe_manager.h"

void TicTacToeManager::get_winner_total(int& X, int& O, int& T)
{
    X = x_win;
    O = o_win;
    T = ties;
}

void TicTacToeManager::save_game(std::unique_ptr<TicTacToe>& game) {
    update_winner_count(game->get_winner());
    games.push_back(std::move(game));
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