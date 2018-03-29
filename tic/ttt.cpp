// ttt.cpp
// Project2


#include "ttt.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

void TicTacToe::SetPlayer()
{
	string name1, name2;
	char select;
	
	cout << "Enter Player 1's name: ";
	cin >> name1;
	cout << "Enter Player 2's name: ";
	cin >> name2;
	player1.name = name1;
	player2.name = name2;
	do
	{
		cout << player1.name << ", would like to be 'X' or 'O' :";
		cin >> select;
	} while ((toupper(select) != 'X' && (toupper(select) != 'O')));
	if (toupper(select)=='O')
		{
			player1.symbol = 'O';
			player2.symbol = 'X';
		}
	cout << "Ok " << player1.name << " you will be " << player1.symbol << " and " << player2.name << " will be " << player2.symbol << endl;
	
}

void TicTacToe::ResetMatch()
{
	char count = '1';

	for (int i=0; i<3; i++)
		{
			for (int j=0; j<3; j++)
			{
				board[i][j]=count;
				count++;
			}
		}
	CurrentWinner = 3;
	moves = 0;
}
void TicTacToe::ResetGame()
{
	cout << "\nStarting a new Game now...\n";
	ResetMatch();
	SetPlayer();
	totalgames = 1;
	player1.currentscore = 0;
	player2.currentscore = 0;
	player1smove = true;
}
void TicTacToe::DisplayBoard()
{
 	cout<<endl << endl;
	cout<<"  " << board[0][0]<< " | " << board[0][1]<< " | "<< board[0][2] << endl;
	cout<<" -----------" << endl;
	cout<<"  " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
	cout<<" -----------" << endl;
	cout<<"  " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl << endl;
}
void TicTacToe::ChoosePosition()
{
	char select = '0';
	bool need2move = true;
	
	while (CurrentWinner == 3)
	{
		if (player1smove)
		{
			cout << "[" << player1.symbol << "]-" << player1.name << "'s move\n";
			while (need2move)
			{
				do
				{
					cin.ignore();	// clears keyboard buffer
					cout << "Please select an empty position(1-9) on the board: ";
					select = cin.get();
				} while (!(select >= '1' && select <= '9'));
				need2move = SetPosition(select, player1.symbol);
			}
			SetMoves();
			player1smove = false;	// player 2's move now
			need2move = true;		// resetting for next move
		}
		else
		{
			cout << "[" << player2.symbol << "]-" << player2.name << "'s move\n";
			while (need2move)
			{
				do
				{
					cin.ignore();	// clears keyboard buffer
					cout << "Please select an empty position(1-9) on the board: ";
					select = cin.get();
				} while (!(select >= '1' && select <= '9'));
				need2move = SetPosition(select, player2.symbol);
			}
			SetMoves();
			player1smove = true;	// player 1's move now
			need2move = true;		// resetting for next move
		}
		DisplayBoard();
		CurrentWinner = CheckforWinner();
	}
}

bool TicTacToe::SetPosition(char select, char sym)
{
	int r, c;
	bool needtomove;

	switch (select)
	{
		case '1':	r = 0;
					c = 0;
					break;	
		case '2':	r = 0;
					c = 1;
					break;
		case '3':	r = 0;
					c = 2;
					break;
		case '4':	r = 1;
					c = 0;
					break;
		case '5':	r = 1;
					c = 1;
					break;
		case '6':	r = 1;
					c = 2;
					break;
		case '7':	r = 2;
					c = 0;
					break;
		case '8':	r = 2;
					c = 1;
					break;
		case '9':	r = 2;
					c = 2;
					break;
	}
	if (board[r][c] == 'X' || board[r][c] == 'O')
	{
		cout << "This position is already taken, please select another!";
		needtomove = true;
	}
	else
	{
		board[r][c] = sym;
		needtomove = false;
	}
	return needtomove;
}

int TicTacToe::CheckforWinner()
{
	int winner = 3;

	//cout << "\nCHECKFORWINNER\n";	// used for tracking while testing

	// checking horizonal and vertical for wins
	for (int c = 0; c <= 2; c++)
	{
		if (board[c][0] == player1.symbol && board[c][1] == player1.symbol && board[c][2] == player1.symbol)
		{
			winner = 1;
			break;
		}
		else if (board[c][0] == player2.symbol && board[c][1] == player2.symbol && board[c][2] == player2.symbol)
		{
			winner = 2;
			break;
		}
		else if (board[0][c] == player1.symbol && board[1][c] == player1.symbol && board[2][c] == player1.symbol)
		{
			winner = 1;
			break;
		}
		else if (board[0][c] == player2.symbol && board[1][c] == player2.symbol && board[2][c] == player2.symbol)
		{
			winner = 2;
			break;
		}
	}
	// checking diagonal for wins
	if (board[0][0] == player1.symbol && board[1][1] == player1.symbol && board[2][2] == player1.symbol)
	{
		winner = 1;
	}
	else if (board[0][0] == player2.symbol && board[1][1] == player2.symbol && board[2][2] == player2.symbol)
	{
		winner = 2;
	}
	if (board[0][2] == player1.symbol && board[1][1] == player1.symbol && board[2][0] == player1.symbol)
	{
		winner = 1;
	}
	else if (board[0][2] == player2.symbol && board[1][1] == player2.symbol && board[2][0] == player2.symbol)
	{
		winner = 2;
	}
	

	if (winner == 1 || winner == 2)
	{
		if (winner == 1)
		{
			cout << player1.name << " wins!!!\n\n\n";
		}
		else
		{
			cout << player2.name << " wins!!!\n\n\n";
		}
		SetScore(winner);
		displayScore();
	}
	else if (moves==9)
	{
		winner = 0;
		cout << "It's a tie!!\n\n\n";
		displayScore();
	}
	return winner;
}

void TicTacToe::displayScore()
{
	// need to format display
	cout<<player1.name<<" Wins\t\t"<<player2.name<<" Wins\t\tTie Games\n";
	cout<<"----------------------------------------------------------------\n";
	cout<<"\t"<<player1.currentscore<<"\t\t\t";
	cout<<player2.currentscore<<"\t\t\t";
	cout << totalgames - (player1.currentscore + player2.currentscore)<<endl<<endl; // calculate tie games
}

void TicTacToe::AddGames()
{
	//cout << "\nADDGAMES\n"; // used for tracking while testing
	totalgames++;
}

void TicTacToe::SetScore(int win)
{
	//cout << "\nSETSCORE\n"; // used for tracking while testing
	if (win == 1)
	{
		player1.currentscore++;
	}
	else
	{
		player2.currentscore++;
	}
}

void TicTacToe::SetMoves()
{
	//cout << "\nSETMOVES\n";  // used for tracking while testing
	moves++;
}
