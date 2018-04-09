#include "ConnectFourPlusUndo.h"
using namespace cell;
using namespace base;
using namespace pluss;
using namespace undo;
ConnectFourPlusUndo::ConnectFourPlusUndo(){
	row=0;
	col=0;
	moveCounter=0;
}

ConnectFourPlusUndo::ConnectFourPlusUndo(int r, int c){
	setRow(r);
	setCol(c);
	moveCounter=0;
}
/*Undo function checks if the move has been made if the move has been made it */
		/* Deletes it by setting the cell equal to '.' again. */
void ConnectFourPlusUndo::undoMove(char move){

	for(int i=0; i<row; i++)
	{
	
		if(gameBoard[i][move-'A'].getValue()!='.' && gameBoard[i][move-'A'].getValue()!=' ')
		{
			gameBoard[i][move-'A'].setValue('.');
			return;			
		}	
	}

}

int ConnectFourPlusUndo::makeMove(char player) {
	int valid = 0;
	string b;
	string filename;
	int flag=0;


	
	while (!valid) {
		cout << endl;
		cout << "Which column would you like to place your piece in? ";
		cin >> b;
		if (cin.eof()){
			exit(1);
		}
		if (b[0] <= 'z' && b[0] >= 'a') {
			b[0] -= 'a' - 'A';
		}
		/*If user chooses to Save the game it invokes the SAVE function.*/
		if (b == "SAVE") {
			cin >> filename;
			player-=1;
			SAVE(filename,player);
			return 0; 
		}
		/*If user chooses to Load the game it invokes the LOAD function.*/
		if (b == "LOAD") {
			cin >> filename;
			player-=1;
			LOAD(filename,player);
			printgameBoard();

			return 0;
		}
  /*If user chooses to UNDO move it invokes the UNDO function and undos move.*/
		if (b == "UNDO") {
			player-=1; /*We keep the turn at the same player.*/
			undoMove(arr[moveCounter-1]);
			arr.pop_back();
			moveCounter--;
			printgameBoard();

			return 0;
		}
	
		/*It checks weather the input is in range or not.*/
		if (!(b[0] >= 'A' && b[0] < 'A' + col) && b != "SAVE" && b != "LOAD" && b!= "UNDO") {
			cout << endl;
			cerr << "Sorry! You didn't input a char in range." << endl;
			cout << "Please input a valid character to continue!" << endl;
		}

		else
			valid = 1;

	}
	/*If the position is empty which is shown by position being equal to '.'*/
							/*it sets the player.*/
	for (int i=0;i<row;i++)
	{
		if (gameBoard[i][b[0]-'A'].getValue()=='.')
		{	
			for (int i = row - 1; i >= 0; i--) {
				if (gameBoard[i][b[0] - 'A'].getValue()== '.' && b != "SAVE" && b != "LOAD" && b!="UNDO") {
					gameBoard[i][b[0] - 'A'].setValue(player);
					printgameBoard();
					arr.push_back(b[0]);
					moveCounter++;
					return 1;

				}
					
			}

		}
	}
	cerr << "That column is full!  Please try a different one:  " << endl;	
	
	printgameBoard();
	return 1;
}

int ConnectFourPlusUndo::LOAD(string filename,char player){
	ifstream myFile;
	char temp;	
	char buffer;
	

		for(int i=0;i<row;i++)
		{
			delete[] gameBoard[i];
		}
		delete [] gameBoard;
		
	 	
	myFile.open(filename);
	if(!(myFile.is_open())) {
		cerr << "Error opening file" << endl;
		return 0;
	}
	else 
	{
    /*Takes the variables needed respectively as in the file saved previously.*/
		myFile>>row;
		myFile.get(buffer);
		myFile>>col;
		myFile.get(buffer);
		myFile>>player;
		myFile.get(buffer);
		/*Allocates memory for gameBoard as much as the row and col value.*/
		gameBoard=new Cell* [row];
            for(int i=0;i<row;i++)
			{
                gameBoard[i]=new Cell[col];
			}
		/*Sets the gameBoard.*/
		for (int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				myFile.get(temp);
				gameBoard[i][j].setValue(temp);
			}
			myFile.get(buffer);		
		}
	}
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++)
			{
				gameBoard[i][j].setPosition(char('A'+i));
			}
		}
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++)
			{
				gameBoard[i][j].setRow(i);
			}
		}

		myFile>>moveCounter;
		arr.resize(moveCounter);//hata cıkabılır
		for(int i=0;i<moveCounter;i++)
		{
			myFile>>arr[i];
		}		
	myFile.close();
	return 1;
}
/*When this function  is invoked it saves the current status of the game.     */
int ConnectFourPlusUndo::SAVE(string filename,char player){
	ofstream myFile;

	myFile.open(filename);
	if(!(myFile.is_open())){
		cerr<<"Error opening file"<<endl;
	}
	else {
		/*It writes the variables below to the file respectively.*/
		myFile<<row;
		myFile<<"\n";
		myFile<<col;
		myFile<<"\n";
		myFile<<player;
		myFile<<"\n";
		/*Sets the gameBoard into the file.*/
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				myFile<<gameBoard[i][j].getValue();
			}
		myFile<<"\n";
		}
		myFile<<moveCounter;
		myFile<<"\n";
		for(int i=0; i<moveCounter; i++)
			{	
				myFile<<arr[i];
				myFile<<endl;
			}

	}
	myFile.close();
	return 1;
}

/*PlayGame function overriden for Undo class. */
void ConnectFourPlusUndo::playGame(char player){
	
	int turn = 0;
	int full=0;
	int flag = 1;
	int win=0;
	cout<<"Enter column size: ";
	cin>>col;
	cout<<"Enter row size: ";
	cin>>row;


	while(row<=0 || col<=0 ){
		cerr<<"Invalid input for column or row! Please try again: "<<endl;
		cin.clear();                   
		cin.ignore(1000, '\n');		   
		cout<<"Enter column size: ";
		cin>>col;
		cout<<"Enter row size: ";
		cin>>row;

	}
	initializegameBoard();
	char ai = aiPlayer();
	while (win == 0)
	{

		char player;
		if (turn%2 == 0)
		{
			player = 'X';
			cout<<"It's player1's turn!"<<endl;
			while(!makeMove(player));
			

		}
		else
		{
			player = 'O';
			cout<<"It's player2's turn!"<<endl;

			if (ai == 'C' || ai =='c' )
			{
				
				playai(player);
				cout<<endl;
				cout<<"Computer played"<<endl;
			}
			else
			{
				while(!makeMove(player));
			}
		}
		turn+=1;
		win = checkWin(player);
		full=fullgameBoard();

		if (full)
			win=1;
	}

}
