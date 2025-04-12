//h

#include <iostream>
#include <string>
#include <vector>
#include "tic_tac_toe.h"

#ifndef tic_tac_toe_manager_h
#define tic_tac_toe_manager_h

class TicTacToeManager
{
public:
    void save_game(TicTacToe game);
    void get_winner_total(int& X, int& O, int& T);

private:
    std::vector<TicTacToe> games;
    int x_win = 0;
    int o_win = 0;
    int ties = 0;
    void update_winner_count(std::string winner);

};

#endif