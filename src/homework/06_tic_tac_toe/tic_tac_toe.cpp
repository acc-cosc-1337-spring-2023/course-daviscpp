#include "tic_tac_toe.h"

using std::cout;

bool TicTacToe::check_board_full()
{
    bool is_full = true;
    for (string& peg : pegs) 
    {
        if (peg == " ")
        {
            is_full = false;
            break;
        }
    }

    return is_full;
}

bool TicTacToe::game_over()
{
    bool is_game_over = false;
    if (check_column_win() || check_row_win() || check_diagonal_win()) 
    {
        is_game_over = true;
        set_winner();
    } 
    else if (check_board_full()) 
    {
        is_game_over = true;
        winner = "C";
    }

    return is_game_over;
}

void TicTacToe::start_game(string first_player)
{
    player = first_player;
    clear_board();
}

void TicTacToe::clear_board()
{
    for (string& peg : pegs) 
    {
        peg = " ";
    }
}

bool TicTacToe::check_column_win()
{
    return false;
}

bool TicTacToe::check_row_win()
{
    return false;
}

bool TicTacToe::check_diagonal_win()
{
    return false;
}

void TicTacToe::mark_board(int position)
{
    pegs[position - 1] = player;
    set_next_player();
}

void TicTacToe::set_next_player()
{
    player = get_player() == "X" ? "O" : "X";
}

void TicTacToe::set_winner()
{
    winner = get_player() == "X" ? "O" : "X";
}

std::istream& operator>>(std::istream& in, TicTacToe& game)
{
    int position;
    for (;;) 
    {
        cout << "Player " << game.get_player() << ", enter a position from 1 to " << game.pegs.size() << ": ";
        if (in >> position) 
        {
            if (position >= 1 && position <= game.pegs.size())
                break;
        } else 
        {
            in.clear();
            in.ignore(80, '\n');
            cout << "Invalid input\n";
        }
    }
    game.mark_board(position);
    return in;
}

std::ostream& operator<<(std::ostream& out, TicTacToe& game)
{
    out << "\n";
    for (auto i = 0; i < game.pegs.size(); i++) 
    {
        out << game.pegs[i];
        if (game.pegs.size() == 9 && (i == 2 || i == 5)) 
        {
            out << "\n";
        } 
        else if (game.pegs.size() == 16 && (i == 3 || i == 7 || i == 11)) 
        {
            out << "\n";
        } 
        else if (i < game.pegs.size() - 1) 
        {
            out << "|";
        }
    }
    
    out << "\n\n";
    return out;
}
