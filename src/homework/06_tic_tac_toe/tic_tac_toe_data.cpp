#include "tic_tac_toe_data.h"
#include <fstream>
#include <iostream>
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"

using std::ofstream;
using std::ifstream;
using std::string;
using std::getline;
using std::cout;
using std::unique_ptr;
using std::make_unique;
using std::move;
using std::ios;

void TicTacToeData::save_games(const std::vector<std::unique_ptr<TicTacToe>>& games) 
{
    ofstream file;
    file.open("game_history.dat", ios::app);
    for(auto& game : games) 
    {
        for(auto& peg : game->get_pegs()) 
        {
            file<<peg;
        }    

        file<<game->get_winner();
        file<<"\n";
    }

    file.close();
}

vector<unique_ptr<TicTacToe>> TicTacToeData::get_games() 
{
    
    //make sure file exists before trying to read it
    std::fstream fs;
    fs.open("game_history.dat", std::ios::out | std::ios::app);
    fs.close();

    string line;
    ifstream infile("game_history.dat",ios::out);
    vector<unique_ptr<TicTacToe>> boards;
    if(infile.is_open()) 
    {
        while(getline(infile, line)) 
        {
            vector<string> pegs;
            for(int i = 0; i < line.size()-1; i++) 
            {
                pegs.push_back(string(1, line[i]));
            }
            
            int lastCharIndex = line.size() - 1;
            string winner = string(1, line[lastCharIndex]);
            unique_ptr <TicTacToe> board;
            if(pegs.size() == 9) 
            {
                board = make_unique<TicTacToe3>(pegs, winner);
            }

            else if(pegs.size() == 16) 
            {
                board = make_unique<TicTacToe4>(pegs, winner);
            }

            boards.push_back(move(board));
        }

        infile.close();
        return boards;
    }
    else 
    {
        cout<<"Unable to open file\n";    
    }
} 