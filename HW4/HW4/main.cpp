#include "ConnectFour.h"

int main(){
	int flag=1;
	int flag2=1;
	int select=0;
	char choice;
	char player1='X';
	char player2='O';
	string filename;
	int flagEnd=1;

	
	while(flag)
	{
		cout<<"Please choose game type."<<endl;
		cout<<"Enter M for multiple and S for single game: "<<endl;
		cin>>choice;
		if(choice!='M' && choice!='m' && choice!='S' && choice!='s')
			cerr<<"You entered wrong letter. Please enter either M or S."<<endl;
		else
			flag=0;
	}

	if(choice=='S' || choice=='s')
	{
		ConnectFour single;
		single.playGame(0);
		single.printgameBoard();
	}

	else if(choice=='M' || choice=='m')
	{
		cout<<"Object 1: "<<endl;
		cout<<"Please enter the name of the file containing the gameBoard for Object 1: "<<endl;
		cin>>filename;
		ConnectFour game1(filename);
		cout<<"Object 2: "<<endl;
		cout<<"Please enter the name of the file containing the gameBoard for Object 2: "<<endl;
		cin>>filename;
		ConnectFour game2(filename);
		cout<<"Object 3: "<<endl;
		cout<<"Please enter the name of the file containing the gameBoard for Object 3: "<<endl;
		cin>>filename;
		ConnectFour game3(filename);
		cout<<"Object 4: "<<endl;
		cout<<"Please enter the name of the file containing the gameBoard for Object 4: "<<endl;
		cin>>filename;
		ConnectFour game4(filename);
		cout<<"Object 5: "<<endl;
		cout<<"Please enter the name of the file containing the gameBoard for Object 5: "<<endl;
		cin>>filename;
		ConnectFour game5(filename);

		while(flag2)
		{
			cout<<"Choose the game. Input number in range 1-5: "<<endl;
			if(!(cin>>select))
			{
				cerr<<"Your input is out of range! Please try again: "<<endl;
				cin.clear();
				cin.ignore(1000,'\n');
				continue;
			}
			if(select>5&&select<1){
				cerr<<"Out of range!!!"<<endl;
			}

			switch(select){
				case 1:
						if(!(game1.endGame())){
							game1.playGame(0);
							game1.printgameBoard();}
						else{
						
						cout<<"The game in this object is finished."<<endl;}
						break;
				case 2: 
						
						if(!(game2.endGame()))
							game2.playGame(0);
						else{
							cout<<"The game in this object is finished."<<endl;
							}
					break;
				case 3: 
						if(!(game3.endGame()))
							game3.playGame(0);
						else
							cout<<"The game in this object is finished."<<endl;
					break;
				case 4:
						if(!(game4.endGame()))
							game4.playGame(0);
						else
							cout<<"The game in this object is finished."<<endl;
					break;
				case 5: 
						if(!(game5.endGame()))
							game5.playGame(0);
						else
							cout<<"The game in this object is finished."<<endl;
					break;
				default:
					cerr<<"Wrong input!!!"<<endl;
			}

			if(game1.endGame() && game2.endGame() && game3.endGame() && game4.endGame() && game5.endGame())
			{
				cout<<"All games ended."<<endl;
				flag2=0;
			}
		}


	}
	

	return 0;


}
