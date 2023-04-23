#include <iostream>
#include <memory>
#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_data.h"

using std::cin;
using std::cout;
using std::unique_ptr;
using std::make_unique;

int main()
{
	string player;
	string game_type;
	unique_ptr <TicTacToe> game;
	string exit_option;
	TicTacToeData data;
	TicTacToeManager manager(data);
	int x_wins = 0;
	int o_wins = 0;
	int ties = 0;

	do
	{
		get_game_type(game, game_type);
		get_first_player(player);
		game->start_game(player);
		cout<<*game;	
		while (!game->game_over())
		{
			cin>>*game;
			cout<<*game;
		}
		
		display_winner(game->get_winner());

		manager.save_game(game);
        manager.get_winner_total(o_wins, x_wins, ties);
		display_totals(x_wins, o_wins, ties);
		get_exit_option(exit_option);

	} while (exit_option != "N" && exit_option != "n");

	cout<<manager;
	display_totals(x_wins, o_wins, ties);

	return 0;
}

void get_first_player(string &player)
{
	do
	{
		cout << "\nEnter X or O: ";
		cin >> player;
		if (player == "x" || player == "X")
			player = "X";
		else if (player == "o" || player == "O")
			player = "O";
		else 
        {
			cout<< "Invalid input";
		}
	} while (player != "X" && player != "O");
}

void display_winner(string winner) 
{
	if(winner == "C") 
    {
		cout<<"The game ended in a tie\n\n";
	}
	else cout<<"The winner is player "<<winner<<"\n\n";	
}

void get_exit_option(string &exit_option)
{
	do
	{
		cout<<"Play another? (Y/N) ";
        cin>>exit_option;		
		if (exit_option == "y" || exit_option == "Y")
			exit_option = "Y";
		else if (exit_option == "n" || exit_option == "N")
			exit_option = "N";
		else 
        {
			cout<< "Invalid input\n";
		}
	} while (exit_option != "Y" && exit_option != "N");
}

void display_totals(int& x_wins, int& o_wins, int& ties) 
{
	cout<<"X wins: "<<x_wins<<"\n";
	cout<<"O wins: "<<o_wins<<"\n";
	cout<<"Ties  : "<<ties<<"\n\n";	
}

void get_game_type(unique_ptr<TicTacToe>& game, string &game_type) 
{
	do
	{
		cout << "\n";
		cout << "Would you like to play TicTacToe with 3x3 or TicTacToe 4x4 size board (enter 3 or 4): ";
		cin >> game_type;
		if (game_type == "3") 
        {
			game = make_unique<TicTacToe3>();
		}
		else if (game_type == "4") 
        {
			game = make_unique<TicTacToe4>();
		}
		else 
        {
			cout << "Invalid input";
		}
	} while (game_type != "3" && game_type != "4");
}