#include "tic_tac_toe_manager.h"

std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager) 
{
    for (auto& idx : manager.games) 
    {
        out << *idx << "\n";
    }

    return out;
}

void TicTacToeManager::save_game(unique_ptr<TicTacToe>& game) 
{
    update_winner_count(game->get_winner());
    games.push_back(move(game));
}

void TicTacToeManager::update_winner_count(string winner) 
{
    if (winner == "X" || "x")
        x_win++;
    else if (winner == "O" || "o")
        o_win++;
    else
        ties++;
}

void TicTacToeManager::get_winner_total(int& o, int& x, int& t) 
{
    o = o_win;
    x = x_win;
    t = ties;
}