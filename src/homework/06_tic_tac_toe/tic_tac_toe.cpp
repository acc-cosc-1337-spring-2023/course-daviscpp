#include "tic_tac_toe.h"

void TicTacToe::start_game(string first_player) 
{
    player = first_player;
    clear_board();
}

void TicTacToe::mark_board(int position) 
{
    pegs[position - 1] = player;
    set_next_player();
}

string TicTacToe::get_player() const 
{
    return player;
}

bool TicTacToe::game_over() 
{
    if (check_board_full() || check_column_win() || check_diagonal_win()) 
    {
        set_winner();
        return true;
    } 
    else if (check_board_full()) 
    {
        winner = "C";
        return true;
    } 
    else 
    {
        return false;
    }
}

void TicTacToe::set_next_player()
 {
    if (player == "X" || "x") 
    {
        player = "O";
    } 
    else 
    {
        player = "X";
    }
}

bool TicTacToe::check_board_full() 
{
    for (auto peg : pegs) 
    {
        if (peg == " ") 
        {
            return false;
        }
    }

    return true;
}

void TicTacToe::clear_board() 
{
    for (int i = 0; i < pegs.size(); i++) 
    {
        pegs[i] = " ";
    }
}

void TicTacToe::restart_game() 
{
    clear_board();
    cout << "Enter the first player (X or O): ";
    string first_player;
    cin >> first_player;
    start_game(first_player);
}

bool TicTacToe::check_diagonal_win() 
{
    if (pegs[0] == pegs[4] && pegs[4] == pegs[8] && pegs[0] != " ") 
    {
        return true;
    } 
    else if (pegs[2] == pegs[4] && pegs[4] == pegs[6] && pegs[2] != " ") 
    {
        return true;
    } 
    else 
    {
        return false;
    }
}

bool TicTacToe::check_row_win() 
{
    if (pegs[0] == pegs[1] && pegs[1] == pegs[2] && pegs[0] != " ") 
    {
        return true;
    } 
    else if (pegs[3] == pegs[4] && pegs[4] == pegs[5] && pegs[3] != " ") 
    {
        return true;
    } 
    else if (pegs[6] == pegs[7] && pegs[7] == pegs[8] && pegs[6] != " ") 
    {
        return true;
    } 
    else 
    {
        return false;
    }
}

bool TicTacToe::check_column_win() 
{
    if (pegs[0] == pegs[3] && pegs[3] == pegs[6] && pegs[0] != " ") 
    {
        return true;
    } 
    else if (pegs[1] == pegs[4] && pegs[4] == pegs[7] && pegs[1] != " ") 
    {
        return true;
    } 
    else if (pegs[2] == pegs[5] && pegs[5] == pegs[8] && pegs[2] != " ") 
    {
        return true;
    } 
    else 
    {
        return false;
    }
}

void TicTacToe::set_winner() 
{
    TicTacToe::get_player();
    if (player == "X" || "x") 
    {
        winner = "O";
    }
    if (player == "O") 
    {
        winner = "X";
    }
}