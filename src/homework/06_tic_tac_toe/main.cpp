#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"

int main() 
{
    auto user_choice = 'n';
    int x_win = 0;
    int o_win = 0;
    int ties = 0;

    TicTacToeManager manager;

    do 
    {
        unique_ptr<TicTacToe> game;
        string game_size;

        do 
        {
            cout << "Would you like to play a board size of 3x3 or 4x4? (enter 3 or 4)\n";
            cin >> game_size;

            if (game_size == "3") 
            {
                game = std::make_unique<TicTacToe3>();
            } 
            else if (game_size == "4") 
            {
                game = std::make_unique<TicTacToe4>();
            }
        } while (!(game_size == "3" || game_size == "4"));

        string first_player = "X";
        cout << "\nEnter an X or O: ";
        cin >> first_player;
        game->start_game(first_player);
        cout << *game;

        do 
        {
            cout << "\nEnter which position (1-9) you would like to mark: ";
            cin >> *game;
            cout << *game;
        } while (game->game_over() == false);

        if (game->game_over() == true) 
        {
            manager.save_game(game);
            manager.get_winner_total(o_win, x_win, ties);

            cout << "The winner is: " << game->get_winner() << "\n\n";
            cout << "****************************\n";
            cout << "Total wins - \nPlayer X: " << x_win << "\n";
            cout << "Player O: " << o_win << "\n" << "Ties: " << ties << "\n\n";
            cout << "****************************\n\n";
            cout << "Game Over. Want to play again? (y or n)";
            cin >> user_choice;
        }
    } while (user_choice == 'y' || user_choice == 'Y');

    return 0;
}