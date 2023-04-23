#include <iostream>
#include <memory>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;
using std::unique_ptr;
using std::vector;

#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

class TicTacToe 
{
    friend ostream& operator<<(ostream& out, const TicTacToe& game);
    friend istream& operator>>(istream& in, TicTacToe& game);

public:
    TicTacToe();
    TicTacToe(int size) : pegs(size * size, " ") {}
    string get_winner() { return winner; }
    void start_game(string first_player);
    void mark_board(int position);
    string get_player() const;
    bool game_over();
    void restart_game();

protected:
    virtual bool check_diagonal_win();
    virtual bool check_column_win();
    virtual bool check_row_win();
    vector<string> pegs;

private:
    void set_winner();
    bool check_board_full();
    void set_next_player();
    void clear_board();
    string player;
    string winner;
};

#endif