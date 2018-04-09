/*                    FATIHA BEQIROVSKI 151044091                             */

#include<iostream>
#include<string>
#include<cstdlib>
#include<istream>

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

void makeMove(char board[][SIZE], int rows, int columns, char player);

/* Function: aiPlayer                                                         */
/* Description: Ask user whether there are 1 or 2 human players to determine  */
/*              whether to run ai or not.                                     */
/* Post-conditions: Must know whether ai should be used or not! Return 1 or 2;*/

int aiPlayer();

/* Function: playai                                                           */
/* Description: ai (computer) makes a move                                    */
/* Parameters: board, rows, columns, which player the computer is             */
/* Pre-conditions: User must say there is only one human.                     */

void playai(char board[][SIZE], int rows, int columns, char player);

/* Function: playGame
/* Description: This function controls the flow of the game. Who's turn it is,*/
/*              let's them move, then checks for a win.                       */ 
/* Parameters: board, rows, columns, pieces, and whether someone has won.     */
/* Post-condition: Determines how the game goes.                              */

void playGame(char board[][SIZE], int rows, int columns, int pieces, int win);

/* Function: checkWin                                                         */
/* Description: Use each "check win" function to see if the user has won the  */
/* 				game horizontally, vertically or diagonally (left-right).     */
/* Parameters: board, rows, columns, pieces needed to win, and the player     */
/* Post-condition: Determines whether a player has won or not!                */

int checkWin(char board[][SIZE], int rows, int columns, int pieces, char player);

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
			cout<<"You can only enter numbers even numbers from 4 to 20!!! Please try again. "<<endl;
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

void makeMove(char board[][SIZE], int rows, int columns, char player){
	int valid = 0;
	char b;
	
	while (!valid)
	{
		cout<<endl;
		cout<<"Which column would you like to place your piece in? ";
		cin>>b;

		if (b <= 'z' && b >= 'a')
			b-='a'-'A';

		if(!(b>='A' && b<'A'+rows))
		{	
			cout<<endl;
			cout<<"Sorry! You didn't input a char in range."<<endl;
			cout<<"Please input a valid character to continue!"<<endl;
		}
		else if (board[0][b-'A'] != '.')
		{
			cout<<board[0][b-'A']<<endl;
			cout<<"That column is full!  Please try a different one:  "<<endl;
		}
		else
			valid=1;

	}
	
	for (int i=rows-1;i>=0; i--) 
	{
		if (board[i][b - 'A'] == '.') 
		{
			board[i][b - 'A'] = player;
			break;
		}
	}

	printBoard(board, rows, columns);
}

int aiPlayer(){
	int ai, valid = 0;
	cout<<endl;
	cout<<"How many humans are playing?" <<endl; 
	cout<<"If you choose 1 you play against computer. "<<endl;
	cout<<"If you choose 2 you will play against user. "<<endl;
	cout<<"Please enter either 1 or 2: ";
	
	while (valid == 0)
	{
		cin>>ai;
		if (ai>2 || ai<1 || cin.fail())
		{ 
			cin.clear();
			cin.ignore(1000, '\n');
			cout<<"Sorry! You didn't enter a 1 or a 2.  Please try again! ";
			valid = 0;
		}
		else
			valid = 1;
	}	
return ai;
}

void playai(char board[][SIZE], int rows, int columns, char player){
	int valid = 0;
	srand(time(NULL));
	int i;
	int b = rand () % columns;
	
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

void playGame(char board[][SIZE], int rows, int columns, int pieces, int win){
	int ai = aiPlayer();
	int turn = 0;
	int full=0;
	
	while (win == 0)
	{
	char player;
		if (turn%2 == 0)
		{
			player = 'X';
			cout<<"It's player1's turn!"<<endl;
			makeMove(board, rows, columns, player);
		}
		else
		{
			player = 'O';
			cout<<"It's player2's turn!"<<endl;
			if (ai == 1)
				playai(board, rows, columns, player);
			else
				makeMove(board, rows, columns, player);
		}
		turn+=1;
		win = checkWin(board, rows, columns, pieces, player);
		full=fullBoard(board, rows, columns);
		
		if (full)
			win=1;
			
	}
}

int checkWin(char board[][SIZE], int rows, int columns, int pieces, char player){
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
	
	for (int i=0;i<rows;i++)
	{ 
		for (int j=0;j<columns;j++)
		{
			if (board[i][j]=='.')
				return 0;
		}
	}
return 1;
}
