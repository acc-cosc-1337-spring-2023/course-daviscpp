#include "tic_tac_toe.h"
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "tic_tac_toe_data.h"

#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

class TicTacToeManager 
{

friend std::ostream& operator<<(std::ostream& out, TicTacToeManager& manager);

public:
    TicTacToeManager() {}
    TicTacToeManager(TicTacToeData data);
    ~TicTacToeManager();
    void save_game(std::unique_ptr<TicTacToe>& game);
    void get_winner_total(int& o, int& x, int& t);
private:
    vector<std::unique_ptr<TicTacToe>> games;
    int x_win{0};
    int o_win{0};
    int ties{0};
    void update_winner_count(string winner);
    TicTacToeData data;
};

void display_totals(int& x_wins, int& o_wins, int& ties);

#endif