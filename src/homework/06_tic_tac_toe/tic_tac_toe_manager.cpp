#include "tic_tac_toe_manager.h"
#include <iostream>
#include <memory>

using std::cout;
using std::unique_ptr;
using std::move;

TicTacToeManager::TicTacToeManager(TicTacToeData data) : data(data) 
{
    vector<unique_ptr<TicTacToe>> games = data.get_games();
    for(auto& game : games)
    {
        update_winner_count(game->get_winner());
    }    
}

TicTacToeManager::~TicTacToeManager() 
{
    data.save_games(games);
}

void TicTacToeManager::save_game(unique_ptr<TicTacToe>& game) 
{
    update_winner_count(game->get_winner());
    games.push_back(move(game));
}

void TicTacToeManager::update_winner_count(string winner) 
{
    if(winner == "X") 
    {
        x_win++;
    }
    else if(winner == "O") 
    {
        o_win++;
    }
    else 
    {
        ties++;
    }
}

std::ostream& operator<<(std::ostream& out, TicTacToeManager& manager) 
{
    for(auto& game : manager.games)
    {
        cout<<*game;
    }
}

void TicTacToeManager::get_winner_total(int& o, int& x, int& t) 
{
    x = x_win;
    o = o_win;
    t = ties;
}