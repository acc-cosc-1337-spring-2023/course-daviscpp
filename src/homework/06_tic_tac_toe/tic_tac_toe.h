#include <string>
#include <vector>
#include <iostream>
#include <memory>

using std::string;
using std::vector;

#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

class TicTacToe 
{
    friend std::istream& operator>>(std::istream& in, TicTacToe& game);
    friend std::ostream& operator<<(std::ostream& out, TicTacToe& game);

public:
    TicTacToe() : pegs(9, " ") {}
    TicTacToe(int size) : pegs(size * size, " ") {}
    TicTacToe(std::vector<string> p, string win) : pegs(p), winner(win) {}

    bool game_over();
    void start_game(string first_player);
    void mark_board(int position);
    string get_player() const { return player; }
    string get_winner() const { return winner; }
    vector<string> get_pegs() const { return pegs; }
    virtual void get_board_type() = 0;

protected:
    std::vector<std::string> pegs;

    virtual bool check_column_win();
    virtual bool check_row_win();
    virtual bool check_diagonal_win();

private:
    string player;
    string winner;

    void set_next_player();
    bool check_board_full();
    void clear_board();
    void set_winner();
};

#endif

void get_first_player(string& player);
void display_winner(string winner);
void get_exit_option(string& exit_option);
void get_game_type(std::unique_ptr<TicTacToe>& game, string& game_type);
