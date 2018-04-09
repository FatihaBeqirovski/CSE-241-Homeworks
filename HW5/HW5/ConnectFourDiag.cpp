#include "ConnectFourDiag.h"
using namespace cell;
using namespace base;
using namespace diagonal;

ConnectFourDiag::ConnectFourDiag(){
	row=0;
	col=0;
}
ConnectFourDiag::ConnectFourDiag(int r,int c){
	setRow(r);
	setCol(c);
}

int ConnectFourDiag::checkWin(char player){
    int ld=0;
    int rd=0;
    int total=0;
	int full=0;
	ld=checkLeftDiagonal(player);
	rd=checkRightDiagonal(player);
    total=rd+ld;
    if (total>0)
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

