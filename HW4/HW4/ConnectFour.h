#ifndef CONNECTFOUR_H
#define CONNECTFOUR_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

class ConnectFour{


    private:
        class Cell {
            private:
                int row;
                int col;
                char position;
                char player;
                char value;
				
			public:
					Cell();
					~Cell();
                	Cell(int rows, int columns);
					bool operator ==(const Cell& rSide)const;
					bool operator !=(const Cell& rSide)const;
                	Cell operator ++();
                	Cell operator ++(int ignore);
					const Cell& operator --();
                	const Cell operator --(int ignore);
                	friend ostream&operator<<(ostream& out,  Cell& prog);
                	friend istream& operator>>(istream& in, Cell& prog);
                	char getPlayer()const;
                	void setPlayer(char player);
                	int getRow()const;
                	void setRow(int rows);
                	int getCol()const;
                	void setCol(int cols);
                	char getPosition()const;
				 	void setPosition(char position);
                	char getValue() const;
                	void setValue(char values);



        };

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
		int checkHorizontal(char player);
        int checkVertical(char player);
        int checkRightDiagonal(char player);
        int checkLeftDiagonal(char player);
        int fullgameBoard ();
		int playai(char player);
        char aiPlayer();		
        int play();
		void play(char position, char player);
		int checkWin(char player);
        int makeMove(char player);
		int SAVE(string filename, char player);
		int LOAD(string filename,char player);
		void initializegameBoard();
		void read(string filename);
		int getRow() const;
		void setRow(int row);
		int getCol() const;
		void setCol(int col);
		char getPlayers();
      	void setPlayers(char playerss);
		static int getLivingCells();
		static int setLivingCells(int cells);
		int getMode()const;
		void setMode(char m);
		char getGameMode()const;
		char setGameMode(char mode);

    public:
		friend ostream&operator<<(ostream& out,  Cell& prog);
        friend istream& operator>>(istream& in, Cell& prog);
		bool operator ==(const ConnectFour& rSide)const;
		bool operator !=(const ConnectFour& rSide)const;
		ConnectFour& operator=(const ConnectFour &rSide);
		ConnectFour();
        ConnectFour(char mode);
		~ConnectFour();
		ConnectFour(ConnectFour &other);
        ConnectFour(int rows, int cols);
		ConnectFour(string filename);
		void printgameBoard();
        int endGame();
        void playGame(char player);
		
		static int livingCells;
		
};
#endif
