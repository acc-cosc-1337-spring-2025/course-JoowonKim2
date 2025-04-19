//h
#include <iostream>
#include <string>
#include <vector>
#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

class TicTacToe
{
public:
    TicTacToe(int size);
    
    bool game_over();
    void start_game(std::string first_player);
    void mark_board(int position);
    void display_board() const;
    std::string get_player() const{return player;}
    std::string get_winner();

protected:
    std::string player;
    std::vector<std::string> pegs;
    std::string winner;

    bool check_board_full();
    virtual bool check_column_win();
    virtual bool check_row_win();
    virtual bool check_diagonal_win();

    void clear_board();
    void set_next_player();
    void set_winner();
};

#endif