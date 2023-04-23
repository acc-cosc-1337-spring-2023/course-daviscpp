#include "tic_tac_toe.h"

#ifndef TICTACTOE_MANAGER_H
#define TICTACTOE_MANAGER_H

class TicTacToeManager 
{
    friend std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager);

public:
    void save_game(unique_ptr<TicTacToe>& game);
    void get_winner_total(int& o, int& x, int& t);

private:
    void update_winner_count(string winner);
    vector<unique_ptr<TicTacToe>> games;
    int x_win{0};
    int o_win{0};
    int ties{0};
};

#endif
