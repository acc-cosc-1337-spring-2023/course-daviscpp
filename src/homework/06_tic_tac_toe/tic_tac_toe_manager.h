//h
#include "tic_tac_toe.h"

#ifndef TICTACTOE_MANAGER_H
#define TICTACTOE_MANAGER_H

class TicTacToeManager
{

friend std::ostream& operator<<(std::ostream& out, const TicTacToeManager& game);
//friend std::istream& operator>>(std::istream& int, TicTacToe& game);

public:
    void save_game(TicTacToe b);
    void get_winner_total(int& o, int& x, int& t);

private:
    void update_winner_count(string winner);
    vector<TicTacToe> games;
    int x_win{0};
    int o_win{0};
    int ties{0};
};

#endif