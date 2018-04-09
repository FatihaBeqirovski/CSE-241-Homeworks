#include "ConnectFourAbstract.h"
using namespace cell;
using namespace base;
/*   Destructor for ConnectFourAbstract class it releases the memory of the gameBoard.*/
ConnectFourAbstract::~ConnectFourAbstract(){
	if(gameBoard!=nullptr)
	{
		for(int i=0;i<row;i++)
		{
			delete[] gameBoard[i];
			
		}
		delete [] gameBoard;
	}
	//--livingCells;	
} 
//sint ConnectFourAbstract::livingCells=0;
/*    Default constructor for class ConnectFourAbstract it sets the gameBoard to 5x5. */
ConnectFourAbstract::ConnectFourAbstract(){
	setRow(5);
	setCol(5);
	player1='X';
	player2='O';
	initializegameBoard();
	//setGameMode('S');
	//livingCells++;
}
/*     This is the ConnectFourAbstract constructor that sets row and col values.*/
ConnectFourAbstract::ConnectFourAbstract(int rows, int cols): row(rows),col(cols){
	setRow(rows);
	setCol(cols);
	player1='X';
	player2='O';
	//setGameMode('S');
	initializegameBoard();
	//printgameBoard();
	//livingCells++;
}
/*             Constructor that sets the mode and gameBoard to 5x5.           */
ConnectFourAbstract::ConnectFourAbstract(char mode){
	setRow(5);
	setCol(5);
	player1='X';
	player2='O';
	initializegameBoard();
	//printgameBoard();
	setGameMode(mode);
	//livingCells++;
}

ConnectFourAbstract::ConnectFourAbstract(ConnectFourAbstract &other){
	row=other.row;
	col=other.col;
	mode=other.mode;	
	gameMode=other.gameMode;
	
	gameBoard= new Cell *[row];
	for(int i=0;i<row;i++){
		gameBoard[i]=new Cell[col];	
	}
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++)
		{
			gameBoard[i][j]=other.gameBoard[i][j];
		}
	}
	initializegameBoard();
}
/*This is the constructor that takes filename as a parameter. Its used in main*/
/*						function for Multi game mode.                         */
ConnectFourAbstract::ConnectFourAbstract(string filename){
	ifstream myfile;
    string line;
	string tempString;
    int max=0;
    int lineCount=0;
    myfile.open(filename);
	gameMode='M';	
	
	if(!myfile.is_open())
    {
        cout<<"Error  opening file!!!";
        cout<<endl;
    }

    else
	{
        while(getline(myfile,line))
		{
            if(line.length()>max) 
            {
                max = line.length();
               
            }
			 ++lineCount;
        }
		/*Allocates memory for gameBoard.*/
        gameBoard=new Cell* [lineCount];
            for(int i=0;i<lineCount;i++)
			{
                gameBoard[i]=new Cell [max];
			}
	}

        myfile.close();

        myfile.open(filename);
		
        if(!myfile.is_open())
        {
            cout << "Error opening file!!!" << endl;
        }
		
        char temp;
		char ch;
		setRow(lineCount);
		setCol(max);
        for (int i=0;i<lineCount;i++)
        {
			getline(myfile,tempString);
            for (int j=0;j<max;j++)
            {
				/*Sets the gameBoard.*/
				temp=tempString[j];
				if(temp=='*')
					temp='.';
                gameBoard[i][j].setValue(temp);
				cout<<temp<<" ";
            }
		cout<<endl;
        }

        myfile.close();
		cout<<"Please choose game mode P for Player vs Player and C for Player vs Computer: "<<endl;
		cin>>choice;
		while (choice!='P' && choice!='p' && choice!='C' && choice!='c')
		{
	
			cerr<<"You didn't enter valid mode. Please try again. Enter either P or C: "<<endl;
			cin>>choice;

		}		
		
}

/*This is the overload of == operator for ConnectFourAbstract it checks if the members*/
						/*are the same or not.*/
bool ConnectFourAbstract::operator==(const ConnectFourAbstract& rSide)const{
	if (row==rSide.row && col==rSide.col && mode==rSide.mode && gameMode==rSide.gameMode){
	
	for (int i=0;i<col;++i)
	{
		for(int j=0;j<row;j++)
		{
			if (gameBoard[i][j].getValue()==rSide.gameBoard[i][j].getValue())
			{
			}
			else
				return false;
		}
	} return true;
	}
	else 
		return false;
} 
/*This function overload the != operator for ConnectFourAbstract class. It checks*/
		/*weather the both sides are same or not.*/
bool ConnectFourAbstract::operator!=(const ConnectFourAbstract &rSide)const{
	return !(*this==rSide);
}

/**********ALL THE SETTERS AND GETTERS NEEDED ARE IMPLEMENTED BELOW.***********/
int ConnectFourAbstract::getMode()const{
	return mode;
}
void ConnectFourAbstract::setMode(char m){
	mode=m;
}
char ConnectFourAbstract::getGameMode()const{
	return gameMode;
}
char ConnectFourAbstract::setGameMode(char mode){
	gameMode=mode;
}
int ConnectFourAbstract::getRow()const{
	return row;
}
int ConnectFourAbstract::getCol()const{
	return col;
}

void ConnectFourAbstract::setRow(int value){
	row=value;
}
void ConnectFourAbstract::setCol(int value){
	col=value;
}

/*This function prints the gameBoard. It puts '.' for empty cells and it marks the*/
					/*positions with letters.*/
void ConnectFourAbstract::printgameBoard(){
	cout<<"The gameBoard currently looks like: "<<endl;

	for(char t='a'; t<'a'+col;t++ )
		cout<<t<<" ";
	cout<<endl;

	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			cout<<gameBoard[i][j].getValue()<<" ";
		}
		cout<<endl;
	}

}
/*			   This function initializes gameBoard it sets the values.        */

void ConnectFourAbstract::initializegameBoard(){
	/*Allocates memory for gameBoard.*/
	/*Allocates memory for gameBoard.*/

	if(gameBoard!=nullptr)
	{
		for(int i=0;i<tempRow;i++)
		{
			delete[] gameBoard[i];
			
		}
		delete [] gameBoard;
	}	

	gameBoard= new Cell*[row];
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++)
		{
			gameBoard[i]=new Cell[col];
		}
	}
	/*Sets gameBoard values.*/
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++)
		{
			gameBoard[i][j].setValue('.');
			gameBoard[i][j].setRow(i);
			gameBoard[i][j].setCol(j);
		}
	}


	


}
/*This function loads the previously saved game. It resizes according to the  */
/*file and it loads the positions and modes saved previously. It changes the  */
							/*games state.*/
int ConnectFourAbstract::LOAD(string filename,char player){
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
                gameBoard[i]=new Cell [col];
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
	myFile.close();
	return 1;
}
/*When this functions is invoked it saves the current status of the game.     */
int ConnectFourAbstract::SAVE(string filename,char player){
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

	}
	myFile.close();
	return 1;
}

/*This function plays computer.*/
int ConnectFourAbstract::play(){
	int comp;
	comp=playai(players);
	for (int i=row-1;i>=0; i--)
	{
		if (gameBoard[i][comp].getValue() == '.')
		{
			gameBoard[i][comp].setValue('O');
			break;
		}
	}
}


/*This function makes moves. It asks the user in which cell wants to place the*/
/*piece. It checks upper/lower case. Also it checks if the user wants to save */
						/*  or load the game.  */
int ConnectFourAbstract::makeMove(char player) {
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

	
		/*It checks weather the input is in range or not.*/
		if (!(b[0] >= 'A' && b[0] < 'A' + col) && b != "SAVE" && b != "LOAD") {
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
				if (gameBoard[i][b[0] - 'A'].getValue()== '.' && b != "SAVE" && b != "LOAD") {
					gameBoard[i][b[0] - 'A'].setValue(player);
					printgameBoard();
					return 1;

				}
					
			}

		}
	}
	cerr << "That column is full!  Please try a different one:  " << endl;	
	
	printgameBoard();
	return 1;

}
/*This is the main function that plays the game. It uses the makeMove function*/
/*to make the moves. It checks the game mode firstly weahter its single or    */
/*								multi game. 								  */
void ConnectFourAbstract::playGame(char player){
	
	int turn = 0;
	int full=0;
	int flag = 1;
	int win=0;
	tempRow=row;
	cout<<"Enter width size: ";
	cin>>col;
	cout<<"Enter height size: ";
	cin>>row;
	
	while(row<=0 || col<=0 ){
		cerr<<"Invalid width or height!"<<endl;
		cin.clear();                   
		cin.ignore(1000, '\n');		   
		cout<<"Enter width size: ";
		cin>>col;
		cout<<"Enter height size: ";
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
/* Checks if the game ended. If the cells of gameBoard are filled with lower case */
/* x or o or if the gameBoard is full it means the game ended so it returns 1.    */
/* Otherwise the game is not done yet so it returns 0;                        */  
int ConnectFourAbstract::endGame(){

	for (int i=0;i<row;i++) {
		for (int j = 0; j < col; j++) {	
			if (gameBoard[i][j].getValue() == 'x' || gameBoard[i][j].getValue() == 'o'){				
				return 1;
			}
			if (fullgameBoard()){
				return 1;
			}
	
		}
	}
	return 0;

}
/* Checks if the gameBoard is full. If therse is no more '.' cells left the gameBoard */
/* 								is full. 									  */
int ConnectFourAbstract::fullgameBoard (){
	int full=0;

	for (auto i=0;i<row;i++)
	{
		for (auto j=0;j<col;j++)
		{
			if (gameBoard[i][j].getValue()=='.')
				return 0;
		}
	}
	return 1;
}
/* The function playai plays the computer. It checks vertically horizontally  */
/* weather the player has set three pieces or not. If it has three pieces it  */
/* blocks the player from wining by placing the next piece. In other cases it */
/* plays randomly.                                                            */
int ConnectFourAbstract::playai(char player){
	int valid = 0;
	srand(time(NULL));
	int i;
	int b = rand () % col;
	int count=0;

	for (int j = 0; j<col; j++)
	{
		for(int i = row-1; i>=0; i--)
		{
			if(gameBoard[i][j].getValue()== 'X')
				count+=1;
			else
				count = 0;
			if (count>2)
			{

				gameBoard[i-1][j].setValue('O');

			}

		}
		count = 0;
	}
	cout<<endl;

	for (int i = 0; i<row; i++)
	{
		for(int j = 0; j<col; j++)
		{

			if(gameBoard[i][j].getValue() == 'X')
				count+=1;
			else
				count = 0;
			if (count>2)
			{

				gameBoard[i][j+1].setValue('O');
			}

		}
		count = 0;
	}
	cout<<endl;
	for(int i = row-1; i >= 0 ; i--)
	{
		if (gameBoard[i][b].getValue() == '.')
		{
			gameBoard[i][b].setValue(player);
			break;
		}

	}
	printgameBoard();
}
int ConnectFourAbstract::checkHorizontal(char player){
/* This function checks the gameBoard horizontally.If player is placed on any cell*/
/* it increases the count for one. If count is 4 it means that the one of the */
/* players has won the game and it turns the players character into lower case*/
/* to indicate that it won. Finally it returns the count.                     */

	int count=0;

	for (int i = 0; i<row; i++)
	{
		for(int j = 0; j<col; j++)
		{

			if(gameBoard[i][j].getValue()==player)
				count+=1;
			else
				count = 0;
			if (count>=4)
			{
				for (int a=0;a<4;a++)
				{
					if (player=='X')
						gameBoard[i][j-a].setValue('x');
					else
						gameBoard[i][j-a].setValue('o');
				}
				return count;
			}
		}
		count = 0;
	}
	cout<<endl;
	return count;
}
int ConnectFourAbstract::checkVertical(char player){
/* This function checks the gameBoard vertically. If player is placed on any cell */
/* it increases the count for one. If count is 4 it means that the one of the */
/* players has won the game and it turns the players character into lower case*/
/* to indicate that it won. Finally it returns the count.                     */
	int count=0;

	for (int j = 0; j<col; j++)
	{
		for(int i = row-1; i>=0; i--)
		{
			if(gameBoard[i][j].getValue() == player)
				count+=1;
			else
				count = 0;
			if (count>=4)
			{
				for (int a=0;a<4;a++)
				{
					if (player=='X')
						gameBoard[i+a][j].setValue('x');
					else
						gameBoard[i+a][j].setValue('o');
				}
				return 1;
			}
		}
		count = 0;
	}
	cout<<endl;
	return count;
}
int ConnectFourAbstract::checkRightDiagonal(char player){
/* This function checks the gameBoard diagonally It checks the right side. If */
/*player is placed on any cell */
/* it increases the count for one. If count is 4 it means that the one of the */
/* players has won the game and it turns the players character into lower case*/
/* to indicate that it won. Finally it returns the count.                     */
	int count=0;
	bool win = false;

	for(int i = row-1; i>=0; i--)
	{
		for(int j =col-1; j>=0; j--)
		{
			for (int z = 0; z<=row-1 && z<=col-1; z++)
			{
				if(i-z>-1 && j-z>-1) {
					if (gameBoard[i - z][j - z].getValue() == player)
						count += 1;
					else
						count = 0;
				}
				if (count==4)
				{
					for (int a=0;a<4;a++)
					{
						if (i-a>-1 && j-a<col){
						if (player=='X')
							gameBoard[i-a][j-a].setValue('x');
						else
							gameBoard[i-a][j-a].setValue('o');
						}
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
int ConnectFourAbstract::checkLeftDiagonal(char player){
/* This function checks the gameBoard diagonally. It checks the left side.    */
/* If player is placed on any cell */
/* it increases the count for one. If count is 4 it means that the one of the */
/* players has won the game and it turns the players character into lower case*/
/* to indicate that it won. Finally it returns the count.                     */
	int count=0;

	for(int i = row-1; i>0; i--)
	{
		for(int j = 0; j<col-1; j++)
		{
			for (int z = 0; z<=col-1; z++)
			{
				if(i-z>-1 && j+z<col){
				if(gameBoard[i-z][j+z].getValue() == player)
					count+=1;

				else
					count = 0;
				}
				if (count==4)
				{
					for (int a=0;a<4;a++)
					{
						if(i-a>-1 && j+a<col){
						if (player=='X')
							gameBoard[i-a][j+a].setValue('x');
						else
							gameBoard[i-a][j+a].setValue('o');
						}

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
/*This function asks the user to choose the game mode. The mode can be player */
/*					vs player or player vs computer.                          */
char ConnectFourAbstract::aiPlayer(){
	char ai;

	cout<<endl;
	cout<<"How many humans are playing?" <<endl;
	cout<<"If you choose C you play against computer. "<<endl;
	cout<<"If you choose P you will play against user. "<<endl;
	cout<<"Please enter either P or C: ";

	cin>>ai;
	while (ai!='P' && ai!='p'&& ai!='C' && ai!='c')
	{

		cerr<<"Sorry! You didn't enter valid mode.  Please try again! ";
		cin>>ai;

	}

	return ai;
}

/*This function checks weather the game is won or not. It takes all the checks*/
/*horizontal,vertical,diagonals checks their values and adds them all. If the */
/*total is bigger than 0 it means that the certain player won the game so it  */
/*prints the Congratulations message.Otherwise if the game gameBoard if full it*/
/*tells the user that it's a draw.                                            */
int ConnectFourAbstract::checkWin(char player){
	int h = 0, v = 0, rd = 0, ld = 0, total = 0;
	int full=0;

	h = checkHorizontal(player);
	v = checkVertical(player);
	rd = checkRightDiagonal(player);
	ld =checkLeftDiagonal(player);
	total = h+v+rd+ld;

	if(total>0)
		cout<<"Congratulations player "<<player<<"!  You won this round of Connect 4!"<<endl;
	else
	{
		full=fullgameBoard();
		if (full)
		{
			cout << "GAME OVER!!! The gameBoard is full. It's a draw."<<endl;

		}

	}
	return total;
}

