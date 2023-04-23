#include "tic_tac_toe.h"

#ifndef TIC_TAC_TOE_3_H
#define TIC_TAC_TOE_3_H

class TicTacToe3 : public TicTacToe {
public:
    TicTacToe3() : TicTacToe(3) {}
    TicTacToe3(std::vector<string> p, std::string winner) : TicTacToe(p, winner) {}
    void get_board_type(){std::cout<<"TicTacToe3\n";} 
private:
    bool check_column_win();
    bool check_row_win();
    bool check_diagonal_win(); 
};

#endif