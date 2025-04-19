#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "tic_tac_toe_4.h"
#include <memory>

TEST_CASE("Verify Test Configuration", "verification") {
    REQUIRE(true == true);
}

TEST_CASE("Test win by first row 4", "[TicTacToe4]") {
    std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe4>();
    game->start_game("X");
    game->mark_board(1);
    game->mark_board(5);
    game->mark_board(2);
    game->mark_board(6);
    game->mark_board(3);
    game->mark_board(7);
    game->mark_board(4);
    REQUIRE(game->game_over() == true);
    REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by first column 4", "[TicTacToe4]") {
    std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe4>();
    game->start_game("O");
    game->mark_board(1);
    game->mark_board(2);
    game->mark_board(5);
    game->mark_board(3);
    game->mark_board(9);
    game->mark_board(4);
    game->mark_board(13);
    REQUIRE(game->game_over() == true);
    REQUIRE(game->get_winner() == "O");
}

TEST_CASE("Test win diagonally from top left 4", "[TicTacToe4]") {
    std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe4>();
    game->start_game("X");
    game->mark_board(1);
    game->mark_board(2);
    game->mark_board(6);
    game->mark_board(3);
    game->mark_board(11);
    game->mark_board(4);
    game->mark_board(16);
    REQUIRE(game->game_over() == true);
    REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win diagonally from top right 4", "[TicTacToe4]") {
    std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe4>();
    game->start_game("O");
    game->mark_board(4);
    game->mark_board(1);
    game->mark_board(7);
    game->mark_board(2);
    game->mark_board(10);
    game->mark_board(3);
    game->mark_board(13);
    REQUIRE(game->game_over() == true);
    REQUIRE(game->get_winner() == "O");
}

TEST_CASE("Test tie game 4", "[TicTacToe4]") {
    std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe4>();
    game->start_game("X");
    game->mark_board(1);
    game->mark_board(2);
    game->mark_board(3);
    game->mark_board(4);
    game->mark_board(5);
    game->mark_board(6);
    game->mark_board(7);
    game->mark_board(8);
    game->mark_board(9);
    game->mark_board(10);
    game->mark_board(11);
    game->mark_board(12);
    game->mark_board(13);
    game->mark_board(14);
    game->mark_board(15);
    game->mark_board(16);
    REQUIRE(game->game_over() == true);
    REQUIRE(game->get_winner() == "");
}