#ifndef CONNECTFOURABSTRACT_H
#define CONNECTFOURABSTRACT_H
#include "Cell.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;
using namespace cell;

namespace base{

class ConnectFourAbstract{
	protected:
		
		Cell **gameBoard;
        int row;
		int tempRow;
        int col;
		char player1;
		char player2;
		char mode;
		char gameMode;
        char players;
		char choice;
		
        int fullgameBoard ();
		int playai(char player);
        char aiPlayer();		
        int play();
		void play(char position, char player);
		
		void initializegameBoard();
		void read(string filename);
		int getRow() const;
		void setRow(int row);
		int getCol() const;
		void setCol(int col);
		char getPlayers();
      	void setPlayers(char playerss);
		//static int getLivingCells();
		//static int setLivingCells(int cells);
		int getMode()const;
		void setMode(char m);
		char getGameMode()const;
		char setGameMode(char mode);

    public:
		virtual int checkHorizontal(char player);
        virtual int checkVertical(char player);
        virtual int checkRightDiagonal(char player);
        virtual int checkLeftDiagonal(char player);
		virtual int checkWin(char player)=0;
        virtual int makeMove(char player);
		virtual int SAVE(string filename, char player);
		virtual int LOAD(string filename,char player);
		friend ostream&operator<<(ostream& out,  Cell& prog);
        friend istream& operator>>(istream& in, Cell& prog);
		bool operator ==(const ConnectFourAbstract& rSide)const;
		bool operator !=(const ConnectFourAbstract& rSide)const;
		ConnectFourAbstract& operator=(const ConnectFourAbstract &rSide);
		~ConnectFourAbstract();
		ConnectFourAbstract();
		ConnectFourAbstract(char mode);
		ConnectFourAbstract(ConnectFourAbstract &other);
        ConnectFourAbstract(int r, int c);
		ConnectFourAbstract(string filename);
		void printgameBoard();
        int endGame();
        virtual void playGame(char player);
		
		//static int livingCells;

};
}
#endif
