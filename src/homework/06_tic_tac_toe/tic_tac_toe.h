//h
#include <string>
#include <vector>
#include <iostream>

using std::string; using std::vector; using std::cout; using std::cin; using std::endl;

#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

void init();

class TicTacToe
{
public:
    string get_winner(){return winner;}
    void start_game(string first_player);
    void mark_board(int position);
    string get_player() const;
    void display_board() const;
    bool game_over();
    void restart_game();
private:
 	void set_winner();
 	bool check_diagonal_win();
    bool check_column_win();
    bool check_row_win();
    bool check_board_full();
    void set_next_player();
    void clear_board();
    string player;
    string winner;
    vector<string> pegs{9, " "};
};

#endif