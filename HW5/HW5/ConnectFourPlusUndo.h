#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "ConnectFourPlus.h"
#ifndef CONNECTFOURPLUSUNDO_H
#define CONNECTFOURPLUSUNDO_H
using namespace std;
using namespace cell;
using namespace base;
using namespace pluss;

namespace undo{
class ConnectFourPlusUndo: public ConnectFourPlus{
	public:
		ConnectFourPlusUndo();
		ConnectFourPlusUndo(int r, int c);
		~ConnectFourPlusUndo();
	
	private:
		int makeMove(char player);
		void playGame(char player);
		int SAVE(string filename,char player);
		int LOAD(string filename,char player);
		vector<char>arr;
		int moveCounter;
		void undoMove(char move);
};
}
#endif



