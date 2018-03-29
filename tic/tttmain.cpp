// tttmain.cpp
// Project2

#include "ttt.cpp"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int menuSelection = 0;
	TicTacToe game1; 

	do
	{
		cout<<"Please choose an option"<<endl;
		do 
		{
			cout<<"1)\tStart a new match"<<endl;
			cout<<"2)\tContinue same match"<<endl;
			cout<<"3)\tExit"<<endl;
			cin>>menuSelection;
		}
		while (menuSelection==0);
		if (menuSelection==1)
		{
			game1.ResetGame();
			game1.DisplayBoard();
			game1.ChoosePosition();
		}
		else if(menuSelection==2)
		{
			game1.ResetMatch();
			game1.AddGames();
			game1.DisplayBoard();
			game1.ChoosePosition();
		}

	}
	while(menuSelection != 3);
	
	return 0;
}
