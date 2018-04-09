/*                    FATIHA BEQIROVSKI 151044091                             */

#include<iostream>
#include<string>
#include<time.h>
#include<cstdlib>
#include<istream>
#include<fstream>


const int SIZE=20;
const int pieces=4; 
const int minSIZE=4;
using namespace std;



/* Function: printBoard                                                       */
/* Description: Prints the 2D array that is the board to the screen.          */
/* Parameters:  2D array board, the number of rows and the number of columns. */
/* Pre-condition: Board must have been built.							      */

void printBoard(char board[][SIZE], int rows, int columns);

/* Function: initializeBoard
/* Description: Fills the board with '.'s.                                    */
/* Parameters: 2D array that is the board, number of rows, number of columns, */ 
/*			   and number of pieces                                           */
/* Pre-conditions: Board must be constructed                                  */
/* Post-conditions: Board should have a . character in each cell.             */
void initializeBoard(char board[][SIZE], int rows, int columns, int pieces);

/* Function: makeMove                                                         */
/* Description: Drop a piece into the board,and have it go down to the bottom.*/
/* Parameters: The board, rows, columns, and the player making the move.      */
/* Post-conditions: piece should fill one of the cells on the board.          */

int makeMove(char board[][SIZE], int& rows, int& columns, char player, int mode);

/* Function: aiPlayer                                                         */
/* Description: Ask user whether there are 1 or 2 human players to determine  */
/*              whether to run ai or not.                                     */
/* Post-conditions: Must know whether ai should be used or not! Return 1 or 2;*/

char aiPlayer();

/* Function: playai                                                           */
/* Description: ai (computer) makes a move. It tries to block the player. If  */                               
/*              there are 3 pieces horizontally of vertically the computer    */
/*              puts the 4th piece on order to prevent the user from wining.  */
/*              Other moves are played randomly.                              */
/* Parameters: board, rows, columns, which player the computer is             */
/* Pre-conditions: User must say there is only one human.                     */

int playai(char board[][SIZE], int rows, int columns, char player);

/* Function: playGame
/* Description: This function controls the flow of the game. Who's turn it is,*/
/*              let's them move, then checks for a win.                       */ 
/* Parameters: board, rows, columns, pieces, and whether someone has won.     */
/* Post-condition: Determines how the game goes.                              */

void playGame(char board[][SIZE], int &rows, int &columns, int pieces, int win);

/* Function: checkWin                                                         */
/* Description: Use each "check win" function to see if the user has won the  */
/* 				game horizontally, vertically or diagonally (left-right).     */
/* Parameters: board, rows, columns, pieces needed to win, and the player     */
/* Post-condition: Determines whether a player has won or not!                */

int checkWin(char board[][SIZE], int rows, int columns, int &pieces, char player);

/* 4 functions bellow check the board vertically, horizontally and diagonally.*/
/* Post-condition: They determine weather there are 4 pieces or not.          */

int checkHorizontal(char board[][SIZE], int rows, int columns, int pieces, char player);

int checkVertical(char board[][SIZE], int rows, int columns, int pieces, char player);

int checkRightDiagonal(char board[][SIZE], int rows, int columns, int pieces, char player);

int checkLeftDiagonal(char board[][SIZE], int rows, int columns, int pieces, char player);

/* Function: fullBoard                                                        */
/* Description: Checks if the board is full. If there are no more '.''s 	  */
/*              left it means that the board is full.                   	  */
/* Paramaters: board, rows, columns.                                      	  */
/* Post-condition: Determines weather the board is full or not.         	  */

int fullBoard (char board[][SIZE], int rows, int columns);

/* Function: LOAD                                                             */
/* Description: It loads the txt file. In txt file the order of things stored */
/*              should be as following: board size, board, player, mode.      */
/* Parameters: It take board as 2D array, and it takes player size and mode   */
/*             with reference. It also has filename of type string which is a */
/*             default argument.                                              */

void LOAD(char board[][SIZE], char &player, int &size, int &mode, string filename="load.txt");

/* Function: SAVE                                                             */
/* Description: It saves the current status of the game in  txt file the order*/
/*              of things stored is as following: board size, board, player,  */
/*              mode.                                                         */
/* Parameters: It take board as 2D array, and it takes player size and mode   */
/*             with reference. It also has filename of type string which is a */
/*             default argument.                                              */

void SAVE(char board[][SIZE], char player, int size, int &mode, string filename="save.txt");

/*	REQUIREMENTS DONE:                                                        */
/*  AI has been improved.                                                     */
/*  Auto is used in fullBoard function.                                       */
/*  Default type is used in LOAD and SAVE functions.                          */
/*  Constant parameter is passed in checkWin function.                        */
/*  Parameters by reference are used in LOAD and SAVE functions.              */
/*  Decltype is used in SAVE function.                                        */
/*  All the errors are printed in cerr objects.                               */
	

int main(int argc, char *argv[]){

	char board[SIZE][SIZE];
	char player1='X';
	char player2='O';
	int rows, columns;

	while (1)
	{
		cout<<"Please enter the board size: "<<endl;
		cin>>rows;

		if (rows<minSIZE || rows> SIZE || rows%2!=0)
		{
			cin.clear();
			cin.ignore(1000,'\n');
			cerr<<"You can only enter numbers even numbers from 4 to 20 !!! Please try again. "<<endl;
		}
		else 
			break;
    }
	columns=rows;
	initializeBoard(board, rows, columns, pieces);
	playGame(board, rows, columns, pieces, 0);
	printBoard(board, rows, columns);

return 0;
}



void printBoard(char board[][SIZE], int rows, int columns){
	cout<<"The board currently looks like: "<<endl;
	for (char t= 'a'; t < 'a'+rows;t++)
		cout<<t<<" ";
		cout<<endl;

	for(int i = 0; i<rows; i++)
	{
		for (int j = 0; j<columns; j++)
		{
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}

void initializeBoard(char board[][SIZE], int rows, int columns, int pieces){

	for(int i = 0; i<rows; i++)
	{
		for(int j = 0; j<columns; j++)
		{
			board[i][j] = '.';

		}
	}
	printBoard(board, rows, columns);
}

int makeMove(char board[][SIZE], int &rows, int &columns, char player, int mode){
	int valid = 0;
	string b;
	string filename;
	
	while (!valid)
	{
		cout<<endl;
		cout<<"Which column would you like to place your piece in? ";
		cin>>b;

		if (b[0] <= 'z' && b[0] >= 'a')
			{b[0]-='a'-'A';}
		
		if(b=="SAVE")
		{
			cin>>filename;
			SAVE(board, player, rows, mode, filename);
			return 0;
		}
		if (b=="LOAD")
		{
			cin>>filename;
			LOAD (board, player, rows, mode, filename);
			columns=rows;			
			printBoard(board, rows, columns);				
			
			return 0;
		}
	
		
		if(!(b[0]>='A' && b[0]<'A'+rows) && b!="SAVE" && b!="LOAD")
		{	
			cout<<endl;
			cerr<<"Sorry! You didn't input a char in range."<<endl;
			cout<<"Please input a valid character to continue!"<<endl;
		}
		
		else if (board[0][b[0]-'A'] != '.' && b!="SAVE" && b!="LOAD")
		{
			cout<<board[0][b[0]-'A']<<endl;
			cerr<<"That column is full!  Please try a different one:  "<<endl;
		}
		else
			valid=1;

	}
	
	for (int i=rows-1;i>=0; i--) 
	{
		if (board[i][b[0] - 'A'] == '.' && b!="SAVE" && b!="LOAD")
		{
			board[i][b[0] - 'A'] = player;
			break;
		}
	}

	printBoard(board, rows, columns);
	return 1;
}

char aiPlayer(){
	char ai;

	cout<<endl;
	cout<<"Please choose the game mode." <<endl; 
	cout<<"If you choose C you play against computer. "<<endl;
	cout<<"If you choose P you will play against user. "<<endl;
	cout<<"Please enter either P or C: ";
	
		cin>>ai;
		while (ai!='P' && ai!='C')
		{ 
			
			cerr<<"Sorry! You didn't enter valid mode.  Please try again! ";
			cin>>ai;
			
		}
		
return ai;
}

int playai(char board[][SIZE], int rows, int columns, char player){
	int valid = 0;
	srand(time(NULL));
	int i;
	int b = rand () % columns;
	int count=0;
	
	for (int j = 0; j<columns; j++)
	{
		for(int i = rows-1; i>=0; i--)
		{
			if(board[i][j] == 'X')
				count+=1;
			else
				count = 0;
			if (count>2)
			{
				
				board[i-1][j]='O';
				
			}
			
		}
		count = 0;
	}
	cout<<endl;

	for (int i = 0; i<rows; i++)
	{
		for(int j = 0; j<columns; j++)
		{

			if(board[i][j] == 'X')
				count+=1;
			else
				count = 0;
			if (count>2)
			{
				
					board[i][j+1]='O';
			}
			
		}
		count = 0;
	}
	cout<<endl;
	for(int i = rows-1; i >= 0 ; i--) 
	{
		if (board[i][b] == '.') 
		{
			board[i][b] = player;
			break;
		}
	
	}
	printBoard(board, rows, columns);
	
	
}

void playGame(char board[][SIZE], int &rows, int &columns, int pieces, int win){
	char ai = aiPlayer();
	int turn = 0;
	int full=0;
	int flag = 1;
	
	while (win == 0)
	{
		char player;
		if (turn%2 == 0)
		{
			player = 'X';
			cout<<"It's player1's turn!"<<endl;	
			while(!makeMove(board, rows, columns, player, ai));
		}
		else
		{
			player = 'O';
			cout<<"It's player2's turn!"<<endl;

			if (ai == 'C')
			{
				playai(board, rows, columns, player);
				cout<<endl;
				cout<<"Computer played"<<endl;
			}
			else 
		
			while(!makeMove(board, rows, columns, player, ai));	
		}
		turn+=1;
		win = checkWin(board, rows, columns, pieces, player);
		full=fullBoard(board, rows, columns);
		
		if (full)
			win=1;
			
	}
}

int checkWin(char board[][SIZE], int rows, int columns, int &pieces, char player){
	int h = 0, v = 0, rd = 0, ld = 0, total = 0;
	int full=0;
   
	h = checkHorizontal(board, rows, columns, pieces, player);
	v = checkVertical(board, rows, columns, pieces, player);
	rd = checkRightDiagonal(board, rows, columns, pieces, player);
	ld =checkLeftDiagonal(board, rows, columns, pieces, player);
	total = h+v+rd+ld;
   
	if(total>0)
		cout<<"Congratulations player "<<player<<"!  You won this round of Connect 4!"<<endl;
	else 
	{
		full=fullBoard(board,rows,columns);
		if (full)
		{
			cout << "GAME OVER!!! The board is full. It's a draw."<<endl;
			
		}
		
	}
return total;
}

int checkHorizontal(char board[][SIZE], int rows, int columns, int pieces, char player){
	int count=0;
	
	for (int i = 0; i<rows; i++)
	{
		for(int j = 0; j<columns; j++)
		{

			if(board[i][j] == player)
				count+=1;
			else
				count = 0;
			if (count>=pieces)
			{
				for (int a=0;a<4;a++)
				{
					if (player=='X')
					board[i][j-a]='x';
					else 
					board[i][j-a]='o';
				}
				return count;
			}
		}
		count = 0;
	}
	cout<<endl;
	return count;
}

int checkVertical(char board[][SIZE], int rows, int columns, int pieces, char player){
	int count=0;
	
	for (int j = 0; j<columns; j++)
	{
		for(int i = rows-1; i>=0; i--)
		{
			if(board[i][j] == player)
				count+=1;
			else
				count = 0;
			if (count>=pieces)
			{
				for (int a=0;a<4;a++)
				{
					if (player=='X')
					board[i+a][j]='x';
					else 
					board[i+a][j]='o';
				}
				return 1;
			}
		}
		count = 0;
	}
	cout<<endl;
	return count;
}

int checkRightDiagonal(char board[][SIZE], int rows, int columns, int pieces, char player){
	int count=0;
	bool win = false;

	for(int i = rows-1; i>=0; i--)
	{
		for(int j =columns-1; j>=0; j--)
		{
			for (int z = 0; z<=rows-1 && z<=columns-1; z++)
			{
				if(board[i-z][j-z] == player)
					count+=1;
				else
		       		count = 0;
					
				if (count==pieces) 
				{
					for (int a=0;a<4;a++)
					{
						if (player=='X')
						board[i-a][j-a]='x';
						else 
						board[i-a][j-a]='o';
					}
					win=true;
				}
			}
			count = 0;
		}
		count = 0;
	}

	if (win)
		
		return 1;
	else
		
		return count;
		
}

int checkLeftDiagonal(char board[][SIZE], int rows, int columns, int pieces, char player){
	int count=0;
	
	for(int i = rows-1; i>0; i--)
	{
		for(int j = 0; j<columns-1; j++)
		{
			for (int z = 0; z<=columns-1; z++)
			{ 
				if(board[i-z][j+z] == player)
					count+=1;   
            
				else
					count = 0;
               
				if (count==pieces)
				{
					for (int a=0;a<4;a++)
					{
						if (player=='X')
							board[i-a][j+a]='x';
						else 
							board[i-a][j+a]='o';
					}
						return 1;
				}
         	}
         	count = 0;
		}
		count = 0;
	}
	
	return count;
}

int fullBoard (char board[][SIZE], int rows, int columns){
	int full=0;
	
	for (auto i=0;i<rows;i++) 
	{ 
		for (auto j=0;j<columns;j++)
		{
			if (board[i][j]=='.')
				return 0;
		}
	}
return 1;
}

void LOAD(char board[][SIZE], char &player, int &size, int &mode, string filename)
{
	char ch;
	char buffer;
	ifstream myfile;
	myfile.open(filename);
	
		myfile>>size;
		myfile.get(buffer);
		

		for (int i=0; i<size; i++)
		{
			for (int j=0; j<size; j++)	
			{ 
				myfile.get(board[i][j]);
			}
		myfile.get(buffer);
		}	
		myfile.get(ch);
		player=ch;
		myfile.get(buffer);

		myfile.get(ch);
		mode=int(ch)-48;
						
		
	myfile.close();

}

void SAVE(char board[][SIZE], char player,int size, int &mode, string filename)
{
	int mod2;
	ofstream myfile;
	myfile.open(filename);	
	
		myfile<<size<<"\n";
		
		for (decltype(size*1)i  = 0; i<size; i++)
		{
			for (int j=0; j<size; j++)	
			{ 
				myfile<<board[i][j];
			}
		myfile<<"\n";
		}

		myfile<<player<<"\n";
		if(mode == 'P')
			mod2= int(mode)-79;
		else
			mod2 = int(mode) - 65;

		myfile<<mod2;
	myfile.close();
}
	

