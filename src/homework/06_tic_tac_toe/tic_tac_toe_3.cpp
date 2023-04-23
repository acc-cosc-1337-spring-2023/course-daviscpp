#include "tic_tac_toe_3.h"

bool TicTacToe3::check_column_win() 
{
    bool is_win = false;
    if (pegs[0] != " " && pegs[0] == pegs[3] && pegs[0] == pegs[6])
    {
        is_win = true;
    }
    else if (pegs[1] != " " && pegs[1] == pegs[4] && pegs[1] == pegs[7])
    {
        is_win = true;
    }
    else if (pegs[2] != " " && pegs[2] == pegs[5] && pegs[2] == pegs[8])
    {
        is_win = true;
    }   

    return is_win;
}

bool TicTacToe3::check_row_win() 
{
    bool is_win = false;
    if (pegs[0] != " " && pegs[0] == pegs[1] && pegs[0] == pegs[2])
    {
        is_win = true;
    }
    else if (pegs[3] != " " && pegs[3] == pegs[4] && pegs[3] == pegs[5])
    {
        is_win = true;
    }
    else if (pegs[6] != " " && pegs[6] == pegs[7] && pegs[6] == pegs[8])
    {
        is_win = true;
    }   

    return is_win;
}

bool TicTacToe3::check_diagonal_win() 
{
    bool is_win = false;
    if (pegs[0] != " " && pegs[0] == pegs[4] && pegs[0] == pegs[8])
    {
        is_win = true;
    }
    else if (pegs[6] != " " && pegs[6] == pegs[4] && pegs[6] == pegs[2])
    {
        is_win = true;
    }
    
    return is_win;
}