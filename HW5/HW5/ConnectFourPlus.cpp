#include "ConnectFourPlus.h"
using namespace cell;
using namespace base;
using namespace pluss;
ConnectFourPlus::ConnectFourPlus()
{
	row=0;
	col=0;
}
ConnectFourPlus::ConnectFourPlus(int r, int c){
	setRow(r);
	setCol(c);
}
int ConnectFourPlus::checkWin(char player){
    int h=0;
    int v=0;
    int total=0;
	int full=0;
	h=checkVertical(player);
	v=checkHorizontal(player);
    total=h+v;
    if (total>0)
	{
		
        cout<<"Congratulations player "<<player<<"!  You won this round of Connect 4!"<<endl;
	}
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


