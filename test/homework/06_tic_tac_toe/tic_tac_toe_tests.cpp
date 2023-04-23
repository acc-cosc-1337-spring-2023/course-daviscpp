#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <memory>
#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"

using std::unique_ptr;
using std::make_unique;

TicTacToeManager manager;
int x = 0;
int o = 0; 
int t = 0;

//TicTacToe3 tests

TEST_CASE("Verify game_over by a tie - TicTacToe3") {
	unique_ptr<TicTacToe> ticTacToe = make_unique<TicTacToe3>();
	ticTacToe->start_game("X");
	ticTacToe->mark_board(2);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(1);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(4);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(3);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(5);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(6);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(7);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(8);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(9);//X
	REQUIRE(ticTacToe->game_over() == true);
	REQUIRE(ticTacToe->get_winner() == "C");
}

TEST_CASE("Verify first player set to X - TicTacToe3") {
	unique_ptr<TicTacToe> ticTacToe = make_unique<TicTacToe3>();
	ticTacToe->start_game("X");
	REQUIRE(ticTacToe->get_player() == "X");	
}

TEST_CASE("Verify first player set to O - TicTacToe3") {
	unique_ptr<TicTacToe> ticTacToe = make_unique<TicTacToe3>();
	ticTacToe->start_game("O");
	REQUIRE(ticTacToe->get_player() == "O");	
}

TEST_CASE("Verify win by first column - TicTacToe3") {
	unique_ptr<TicTacToe> ticTacToe = make_unique<TicTacToe3>();
	ticTacToe->start_game("X");
	ticTacToe->mark_board(1);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(2);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(4);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(3);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(7);//X
	REQUIRE(ticTacToe->game_over() == true);	
	REQUIRE((ticTacToe->get_winner() == "X" || ticTacToe->get_winner() == "O"));	
}

TEST_CASE("Verify win by second column - TicTacToe3") {
	unique_ptr<TicTacToe> ticTacToe = make_unique<TicTacToe3>();
	ticTacToe->start_game("X");
	ticTacToe->mark_board(2);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(1);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(5);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(3);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(8);//X
	REQUIRE(ticTacToe->game_over() == true);	
	REQUIRE((ticTacToe->get_winner() == "X" || ticTacToe->get_winner() == "O"));	
}

TEST_CASE("Verify win by third column - TicTacToe3") {
	unique_ptr<TicTacToe> ticTacToe = make_unique<TicTacToe3>();
	ticTacToe->start_game("X");
	ticTacToe->mark_board(3);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(1);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(6);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(4);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(9);//X
	REQUIRE(ticTacToe->game_over() == true);	
	REQUIRE((ticTacToe->get_winner() == "X" || ticTacToe->get_winner() == "O"));	
}

TEST_CASE("Verify win by first row - TicTacToe3") {
	unique_ptr<TicTacToe> ticTacToe = make_unique<TicTacToe3>();
	ticTacToe->start_game("X");
	ticTacToe->mark_board(1);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(4);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(2);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(5);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(3);//X
	REQUIRE(ticTacToe->game_over() == true);	
	REQUIRE((ticTacToe->get_winner() == "X" || ticTacToe->get_winner() == "O"));	
}

TEST_CASE("Verify win by second row - TicTacToe3") {
	unique_ptr<TicTacToe> ticTacToe = make_unique<TicTacToe3>();
	ticTacToe->start_game("X");
	ticTacToe->mark_board(4);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(1);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(5);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(2);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(6);//X
	REQUIRE(ticTacToe->game_over() == true);	
	REQUIRE((ticTacToe->get_winner() == "X" || ticTacToe->get_winner() == "O"));	
}

TEST_CASE("Verify win by third row - TicTacToe3") {
	unique_ptr<TicTacToe> ticTacToe = make_unique<TicTacToe3>();
	ticTacToe->start_game("X");
	ticTacToe->mark_board(7);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(1);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(8);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(2);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(9);//X
	REQUIRE(ticTacToe->game_over() == true);	
	REQUIRE((ticTacToe->get_winner() == "X" || ticTacToe->get_winner() == "O"));	
}

TEST_CASE("Verify win diagonally from top left - TicTacToe3") {
	unique_ptr<TicTacToe> ticTacToe = make_unique<TicTacToe3>();
	ticTacToe->start_game("X");
	ticTacToe->mark_board(1);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(2);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(5);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(3);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(9);//X
	REQUIRE(ticTacToe->game_over() == true);	
	REQUIRE((ticTacToe->get_winner() == "X" || ticTacToe->get_winner() == "O"));
}

TEST_CASE("Verify win diagonally from bottom left - TicTacToe3") {
	unique_ptr<TicTacToe> ticTacToe = make_unique<TicTacToe3>();
	ticTacToe->start_game("X");
	ticTacToe->mark_board(7);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(2);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(5);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(4);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(3);//X
	REQUIRE(ticTacToe->game_over() == true);	
	REQUIRE((ticTacToe->get_winner() == "X" || ticTacToe->get_winner() == "O"));
}

TEST_CASE("Verify manager get winner total - winner X first time - TicTacToe3") {
	unique_ptr<TicTacToe> ticTacToe = make_unique<TicTacToe3>();
	ticTacToe->start_game("X");
	ticTacToe->mark_board(7);//X
	ticTacToe->mark_board(2);//O
	ticTacToe->mark_board(5);//X
	ticTacToe->mark_board(4);//O
	ticTacToe->mark_board(3);//X
	REQUIRE(ticTacToe->game_over() == true);
	manager.save_game(ticTacToe);
	manager.get_winner_total(o, x, t);
	REQUIRE(x == 1);
}

TEST_CASE("Verify manager get winner total - winner O first time - TicTacToe3") {
	unique_ptr<TicTacToe> ticTacToe = make_unique<TicTacToe3>();
	ticTacToe->start_game("O");
	ticTacToe->mark_board(7);//O
	ticTacToe->mark_board(2);//X
	ticTacToe->mark_board(5);//O
	ticTacToe->mark_board(4);//X
	ticTacToe->mark_board(3);//O
	REQUIRE(ticTacToe->game_over() == true);	
	manager.save_game(ticTacToe);
	manager.get_winner_total(o, x, t);
	REQUIRE(o == 1);
}

TEST_CASE("Verify manager get winner total - tie game first time - TicTacToe3") {
	unique_ptr<TicTacToe> ticTacToe = make_unique<TicTacToe3>();
	ticTacToe->start_game("X");
	ticTacToe->mark_board(2);//X
	ticTacToe->mark_board(1);//O
	ticTacToe->mark_board(4);//X
	ticTacToe->mark_board(3);//O
	ticTacToe->mark_board(5);//X
	ticTacToe->mark_board(6);//O
	ticTacToe->mark_board(7);//X
	ticTacToe->mark_board(8);//O
	ticTacToe->mark_board(9);//X
	REQUIRE(ticTacToe->game_over() == true);	
	manager.save_game(ticTacToe);
	manager.get_winner_total(o, x, t);
	REQUIRE(t == 1);
}

TEST_CASE("Verify manager get winner total - winner X second time - TicTacToe3") {
	unique_ptr<TicTacToe> ticTacToe = make_unique<TicTacToe3>();
	ticTacToe->start_game("X");
	ticTacToe->mark_board(7);//X
	ticTacToe->mark_board(2);//O
	ticTacToe->mark_board(5);//X
	ticTacToe->mark_board(4);//O
	ticTacToe->mark_board(3);//X
	REQUIRE(ticTacToe->game_over() == true);	
	manager.save_game(ticTacToe);
	manager.get_winner_total(o, x, t);
	REQUIRE(x == 2);
}

TEST_CASE("Verify manager get winner total - winner O second time - TicTacToe3") {
	unique_ptr<TicTacToe> ticTacToe = make_unique<TicTacToe3>();
	ticTacToe->start_game("O");
	ticTacToe->mark_board(7);//O
	ticTacToe->mark_board(2);//X
	ticTacToe->mark_board(5);//O
	ticTacToe->mark_board(4);//X
	ticTacToe->mark_board(3);//O
	REQUIRE(ticTacToe->game_over() == true);	
	manager.save_game(ticTacToe);
	manager.get_winner_total(o, x, t);
	REQUIRE(o == 2);
}

TEST_CASE("Verify manager get winner total - tie game second time - TicTacToe3") {
	unique_ptr<TicTacToe> ticTacToe = make_unique<TicTacToe3>();
	ticTacToe->start_game("X");
	ticTacToe->mark_board(2);//X
	ticTacToe->mark_board(1);//O
	ticTacToe->mark_board(4);//X
	ticTacToe->mark_board(3);//O
	ticTacToe->mark_board(5);//X
	ticTacToe->mark_board(6);//O
	ticTacToe->mark_board(7);//X
	ticTacToe->mark_board(8);//O
	ticTacToe->mark_board(9);//X
	REQUIRE(ticTacToe->game_over() == true);	
	manager.save_game(ticTacToe);
	manager.get_winner_total(o, x, t);
	REQUIRE(t == 2);
}

//TicTacToe4 tests

TEST_CASE("Verify game_over by a tie - TicTacToe4") {
	unique_ptr<TicTacToe> ticTacToe = make_unique<TicTacToe4>();
	ticTacToe->start_game("X");
	ticTacToe->mark_board(1);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(2);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(3);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(4);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(5);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(6);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(7);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(8);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(9);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(10);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(11);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(12);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(14);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(13);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(16);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(15);//O
	REQUIRE(ticTacToe->game_over() == true);
	REQUIRE(ticTacToe->get_winner() == "C");
}

TEST_CASE("Verify first player set to X - TicTacToe4") {
	unique_ptr<TicTacToe> ticTacToe = make_unique<TicTacToe4>();
	ticTacToe->start_game("X");
	REQUIRE(ticTacToe->get_player() == "X");	
}

TEST_CASE("Verify first player set to O - TicTacToe4") {
	unique_ptr<TicTacToe> ticTacToe = make_unique<TicTacToe4>();
	ticTacToe->start_game("O");
	REQUIRE(ticTacToe->get_player() == "O");	
}

TEST_CASE("Verify win by first column - TicTacToe4") {
	unique_ptr<TicTacToe> ticTacToe = make_unique<TicTacToe4>();
	ticTacToe->start_game("X");
	ticTacToe->mark_board(1);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(2);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(5);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(6);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(9);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(10);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(13);//X	
	REQUIRE(ticTacToe->game_over() == true);	
	REQUIRE((ticTacToe->get_winner() == "X" || ticTacToe->get_winner() == "O"));	
}

TEST_CASE("Verify win by second column - TicTacToe4") {
	unique_ptr<TicTacToe> ticTacToe = make_unique<TicTacToe4>();
	ticTacToe->start_game("X");
	ticTacToe->mark_board(1);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(2);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(5);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(6);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(9);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(10);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(11);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(14);//O
	REQUIRE(ticTacToe->game_over() == true);	
	REQUIRE((ticTacToe->get_winner() == "X" || ticTacToe->get_winner() == "O"));	
}

TEST_CASE("Verify win by third column - TicTacToe4") {
	unique_ptr<TicTacToe> ticTacToe = make_unique<TicTacToe4>();
	ticTacToe->start_game("X");
	ticTacToe->mark_board(3);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(2);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(7);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(6);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(11);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(10);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(15);//X
	REQUIRE(ticTacToe->game_over() == true);	
	REQUIRE((ticTacToe->get_winner() == "X" || ticTacToe->get_winner() == "O"));	
}

TEST_CASE("Verify win by fourth column - TicTacToe4") {
	unique_ptr<TicTacToe> ticTacToe = make_unique<TicTacToe4>();
	ticTacToe->start_game("X");
	ticTacToe->mark_board(4);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(2);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(8);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(6);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(12);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(10);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(16);//X
	REQUIRE(ticTacToe->game_over() == true);	
	REQUIRE((ticTacToe->get_winner() == "X" || ticTacToe->get_winner() == "O"));	
}

TEST_CASE("Verify win by first row - TicTacToe4") {
	unique_ptr<TicTacToe> ticTacToe = make_unique<TicTacToe4>();
	ticTacToe->start_game("X");
	ticTacToe->mark_board(1);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(5);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(2);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(6);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(3);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(7);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(4);//X
	REQUIRE(ticTacToe->game_over() == true);	
	REQUIRE((ticTacToe->get_winner() == "X" || ticTacToe->get_winner() == "O"));	
}

TEST_CASE("Verify win by second row - TicTacToe4") {
	unique_ptr<TicTacToe> ticTacToe = make_unique<TicTacToe4>();
	ticTacToe->start_game("X");
	ticTacToe->mark_board(1);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(5);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(2);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(6);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(3);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(7);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(9);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(8);//O
	REQUIRE(ticTacToe->game_over() == true);	
	REQUIRE((ticTacToe->get_winner() == "X" || ticTacToe->get_winner() == "O"));	
}

TEST_CASE("Verify win by third row - TicTacToe4") {
	unique_ptr<TicTacToe> ticTacToe = make_unique<TicTacToe4>();
	ticTacToe->start_game("X");
	ticTacToe->mark_board(9);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(5);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(10);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(6);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(11);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(7);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(12);//X
	REQUIRE(ticTacToe->game_over() == true);	
	REQUIRE((ticTacToe->get_winner() == "X" || ticTacToe->get_winner() == "O"));	
}

TEST_CASE("Verify win by fourth row - TicTacToe4") {
	unique_ptr<TicTacToe> ticTacToe = make_unique<TicTacToe4>();
	ticTacToe->start_game("X");
	ticTacToe->mark_board(13);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(5);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(14);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(6);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(15);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(7);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(16);//X
	REQUIRE(ticTacToe->game_over() == true);	
	REQUIRE((ticTacToe->get_winner() == "X" || ticTacToe->get_winner() == "O"));	
}

TEST_CASE("Verify win diagonally from top left - TicTacToe4") {
	unique_ptr<TicTacToe> ticTacToe = make_unique<TicTacToe4>();
	ticTacToe->start_game("X");
	ticTacToe->mark_board(1);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(2);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(6);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(3);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(11);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(4);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(16);//X
	REQUIRE(ticTacToe->game_over() == true);	
	REQUIRE((ticTacToe->get_winner() == "X" || ticTacToe->get_winner() == "O"));
}

TEST_CASE("Verify win diagonally from bottom left - TicTacToe4") {
	unique_ptr<TicTacToe> ticTacToe = make_unique<TicTacToe4>();
	ticTacToe->start_game("X");
	ticTacToe->mark_board(13);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(1);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(10);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(2);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(7);//X
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(3);//O
	REQUIRE(ticTacToe->game_over() == false);
	ticTacToe->mark_board(4);//X
	REQUIRE(ticTacToe->game_over() == true);	
	REQUIRE((ticTacToe->get_winner() == "X" || ticTacToe->get_winner() == "O"));
}

TEST_CASE("Verify manager get winner total - winner X third time - TicTacToe4") {
	unique_ptr<TicTacToe> ticTacToe = make_unique<TicTacToe4>();
	ticTacToe->start_game("X");
	ticTacToe->mark_board(1);//X
	ticTacToe->mark_board(2);//O
	ticTacToe->mark_board(5);//X
	ticTacToe->mark_board(6);//O
	ticTacToe->mark_board(9);//X
	ticTacToe->mark_board(10);//O
	ticTacToe->mark_board(13);//X	
	REQUIRE(ticTacToe->game_over() == true);
	manager.save_game(ticTacToe);
	manager.get_winner_total(o, x, t);
	REQUIRE(x == 3);
}

TEST_CASE("Verify manager get winner total - winner O third time - TicTacToe4") {
	unique_ptr<TicTacToe> ticTacToe = make_unique<TicTacToe4>();
	ticTacToe->start_game("O");
	ticTacToe->mark_board(1);//O
	ticTacToe->mark_board(2);//X
	ticTacToe->mark_board(5);//O
	ticTacToe->mark_board(6);//X
	ticTacToe->mark_board(9);//O
	ticTacToe->mark_board(10);//X
	ticTacToe->mark_board(13);//O	
	REQUIRE(ticTacToe->game_over() == true);	
	manager.save_game(ticTacToe);
	manager.get_winner_total(o, x, t);
	REQUIRE(o == 3);
}

TEST_CASE("Verify manager get winner total - tie game third time - TicTacToe4") {
	unique_ptr<TicTacToe> ticTacToe = make_unique<TicTacToe4>();
	ticTacToe->start_game("X");
	ticTacToe->mark_board(1);//X
	ticTacToe->mark_board(2);//O
	ticTacToe->mark_board(3);//X
	ticTacToe->mark_board(4);//O
	ticTacToe->mark_board(5);//X
	ticTacToe->mark_board(6);//O
	ticTacToe->mark_board(7);//X
	ticTacToe->mark_board(8);//O
	ticTacToe->mark_board(9);//X
	ticTacToe->mark_board(10);//O
	ticTacToe->mark_board(11);//X
	ticTacToe->mark_board(12);//O
	ticTacToe->mark_board(14);//X
	ticTacToe->mark_board(13);//O
	ticTacToe->mark_board(16);//X
	ticTacToe->mark_board(15);//O
	manager.save_game(ticTacToe);
	manager.get_winner_total(o, x, t);
	REQUIRE(t == 3);
}

TEST_CASE("Verify manager get winner total - winner X fourth time - TicTacToe4") {
	unique_ptr<TicTacToe> ticTacToe = make_unique<TicTacToe4>();
	ticTacToe->start_game("X");
	ticTacToe->mark_board(1);//X
	ticTacToe->mark_board(2);//O
	ticTacToe->mark_board(5);//X
	ticTacToe->mark_board(6);//O
	ticTacToe->mark_board(9);//X
	ticTacToe->mark_board(10);//O
	ticTacToe->mark_board(13);//X	
	REQUIRE(ticTacToe->game_over() == true);
	manager.save_game(ticTacToe);
	manager.get_winner_total(o, x, t);
	REQUIRE(x == 4);
}

TEST_CASE("Verify manager get winner total - winner O fourth time - TicTacToe4") {
	unique_ptr<TicTacToe> ticTacToe = make_unique<TicTacToe4>();
	ticTacToe->start_game("O");
	ticTacToe->mark_board(1);//O
	ticTacToe->mark_board(2);//X
	ticTacToe->mark_board(5);//O
	ticTacToe->mark_board(6);//X
	ticTacToe->mark_board(9);//O
	ticTacToe->mark_board(10);//X
	ticTacToe->mark_board(13);//O	
	REQUIRE(ticTacToe->game_over() == true);	
	manager.save_game(ticTacToe);
	manager.get_winner_total(o, x, t);
	REQUIRE(o == 4);
}

TEST_CASE("Verify manager get winner total - tie game fourth time - TicTacToe4") {
	unique_ptr<TicTacToe> ticTacToe = make_unique<TicTacToe4>();
	ticTacToe->start_game("X");
	ticTacToe->mark_board(1);//X
	ticTacToe->mark_board(2);//O
	ticTacToe->mark_board(3);//X
	ticTacToe->mark_board(4);//O
	ticTacToe->mark_board(5);//X
	ticTacToe->mark_board(6);//O
	ticTacToe->mark_board(7);//X
	ticTacToe->mark_board(8);//O
	ticTacToe->mark_board(9);//X
	ticTacToe->mark_board(10);//O
	ticTacToe->mark_board(11);//X
	ticTacToe->mark_board(12);//O
	ticTacToe->mark_board(14);//X
	ticTacToe->mark_board(13);//O
	ticTacToe->mark_board(16);//X
	ticTacToe->mark_board(15);//O
	manager.save_game(ticTacToe);
	manager.get_winner_total(o, x, t);
	REQUIRE(t == 4);
}