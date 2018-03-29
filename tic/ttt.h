// ttt.h
// Project2

#include <string>

using namespace std;

#ifndef TTT_H
#define TTT_H


// struct

struct Player
{
	string name;
	char symbol;
	int currentscore;

	Player()
	{
		name = "P";
		symbol = 'T';
		currentscore = 0;
	}
};


// class definition
class TicTacToe
{
	private:
		Player player1;
		Player player2;
		int CurrentWinner = 3; 
		char board[3][3];
		int totalgames = 1;
		bool player1smove = true;	// set so player 1 move's 1st
		int moves = 0;

	public:
		TicTacToe()
		{
			player1.name = "Player 1";
			player1.symbol = 'X';
			player2.name = "Player 2";
			player2.symbol = 'O';
		}
		
		void SetPlayer();
		void ResetMatch();
		void ResetGame();
		void DisplayBoard();
		void ChoosePosition();
		bool SetPosition(char,char);
		int CheckforWinner();
		void displayScore();
		void AddGames();
		void SetScore(int);
		void SetMoves();
};

#endif
